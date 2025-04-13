#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

float tradius = 200.0;
float sradius = 300.0;

template <typename T>
struct node {
    T data;
    node<T>* next;
};

template <typename T>
class Queue //implemented using circular singly linked list
{
	node<T>* front;
	node<T>* rear;
	int size;
	int initialsize;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		size = 0;
		initialsize = 0;
	}
	void enqueue(T val)
	{
		node<T>* temp = new node<T>;
		temp->data = val;
		if (front == NULL)
		{
			front = rear = temp;
			front->next = front;
		}
		else
		{
			rear->next = temp;
			temp->next = front;
			rear = temp;
		}
		size++;
		initialsize++;
	}
	node<T>* getfront()
	{
		return front;
	}
	void dequeue()
	{
		if (!IsEmpty())
		{
			node<T>* temp = front;
			front = front->next;
			rear->next = front;
			delete temp;
			size--;
		}

	}
	T top()
	{
		if (!IsEmpty())
			return front->data;
		else
			return NULL;
	}
	int getsize()
	{
		return size;
	}
	int getinitialsize()
	{
		return initialsize;
	}
	bool IsEmpty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	void march()
	{
		front = front->next;
		rear = rear->next;
	}
	void print()
	{
		node<T>* temp = front;
		do
		{
			cout << temp->data << "\t";
			temp = temp->next;
		} while (temp != rear->next);
		cout << endl;

	}
	~Queue()
	{
		while (!IsEmpty())
		{
			dequeue();
		}
	}
};

void drawQueue(sf::RenderWindow& window, Queue<int>& q1) 
{
	//soldier
    node<int>* temp = q1.getfront();
	sf::Sprite sol;
	sf::Texture solTexture;
	solTexture.loadFromFile("soldier.png");
	sol.setTexture(solTexture);
	sol.setScale(0.1,0.1);

	//Text
    sf::Font font;
    font.loadFromFile("Arial.ttf");
    sf::Text txt;
    txt.setFont(font);
    txt.setCharacterSize(24);
    txt.setFillColor(sf::Color::White);
    
	// to find the midpoint of the window
    float centerX = window.getSize().x / 2.0; 
    float centerY = window.getSize().y / 2.0;

	//control of radius of soldiers
	if ((q1.getsize() == (3 * q1.getinitialsize()) / 4) || q1.getsize() == (q1.getinitialsize()) / 2 || q1.getsize() == (q1.getinitialsize()) / 4)
	{
		tradius = tradius - 50;
		sradius = sradius - 50;
	}

    for (int i = 0; i < q1.getsize(); i++)
	{
        int number = temp->data;
        float angle = 2 * 3.14159265 * i / q1.getsize(); // 2π x current/total

        //setting the xy coordinates
		float tx = centerX + tradius * cos(angle);
        float ty = centerY + tradius * sin(angle);
		float sx = centerX + sradius * cos(angle);
		float sy = centerY + sradius * sin(angle);

		//positioning of the coordinates
        txt.setString(to_string(number));
        txt.setPosition(tx, ty);
		sol.setPosition(sx-30, sy-50);

        window.draw(txt);
		window.draw(sol);

        temp = temp->next;
    }
}

int main() 
{
    int n, k;
    cout << "Enter N : ";
    cin >> n;
    cout << "Enter K : ";
    cin >> k;
	k--;
	bool flag = false;
    Queue<int> q1;
    for (int i = 1; i <= n; i++) 
	{
        q1.enqueue(i);
    }
	q1.print();

	//Window definition
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Josephus Problem");
    window.setFramerateLimit(1);

    while (window.isOpen() && !q1.IsEmpty() && !flag)
	{
        window.clear();
        drawQueue(window, q1);
        window.display();

        for (int i = 0; i < k; i++) 
		{
            q1.march();
        }
		if (k >= 0)
		{
			q1.dequeue();
		}
		else
			flag = true;
    }
	q1.print();
    return 0;
}
