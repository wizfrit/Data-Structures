#include <iostream>
#include<cstring>
#include<string.h>
#include<cmath>
using namespace std;

template <typename T>
struct node
{
	T data;
	node<T>* next;
public:
	node()
	{
		data = '\0';
		next = NULL;
	}
};
template <typename T>
class Queue //implemented using singly linked list
{
	node<T>* front;
	node<T>* rear;
	int size;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		size = 0;
	}
	void enqueue(T val)
	{
		node<T>* temp = new node<T>;
		temp->data = val;
		if (front == NULL)
		{
			front = rear = temp;
		}
		else 
		{
			rear->next = temp;
			rear = temp;
		}
		size++;
	}
	void dequeue()
	{
		if (!IsEmpty())
		{
			node<T>* temp = front;
			front = front->next;
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
	bool IsEmpty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	void print()
	{
		node<T>* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	
	}
	~Queue()
	{
		while (front != NULL)
		{
			node<T>* temp = front;
			front = front->next;
			delete temp;
		}
	}
};
void intradix(Queue<int> &data, int k) //function for int radix sorting
{
	Queue<int>* q1 = new Queue<int>[10];
	for (int i = 0; i < k; i++) //till the count of digits
	{
		int exp = pow(10, i);
		for (int j = data.getsize(); j > 0; j--) //till the count of numbers
		{
			int temp = data.top();
			data.dequeue();
			if (temp < 0) //for negative numbers if given
			{
				q1[0].enqueue(temp);
			}
			else
			{
				int pos = (temp / exp) % 10;
				q1[pos].enqueue(temp);
			}

		}
		for (int i = 0; i < 10; i++) //for re enqueing of sorted data according to place value 
		{
			while (!q1[i].IsEmpty())
			{
				data.enqueue(q1[i].top());
				q1[i].dequeue();
			}
		}
	}
}

void stradix(Queue<string>& data, int k) //function for int radix sorting
{
	Queue<string>* q1 = new Queue<string>[256];
	for (int i = k-1; i >= 0; i--) //till the count of elements
	{
		for (int j = data.getsize(); j > 0; j--) //the count of strings
		{
			string temp = data.top();
			data.dequeue();
			q1[temp[i]].enqueue(temp);

		}
		for (int i = 0; i < 256; i++) //for re enqueing of sorted data according to place value 
		{
			while (!q1[i].IsEmpty())
			{
				data.enqueue(q1[i].top());
				q1[i].dequeue();
			}
		}
	}
}
int main()
{
	//Part 1
	Queue<int> q1;
	q1.enqueue(45);
	q1.enqueue(37);
	q1.enqueue(90);
	q1.enqueue(72);
	q1.enqueue(12);
	q1.enqueue(98);
	q1.enqueue(99);
	
	q1.print();

	intradix(q1, 2);
	q1.print();

	//Part 2
	Queue<string> q2;
	q2.enqueue("qr");
	q2.enqueue("as");
	q2.enqueue("iu");
	q2.enqueue("jk");
	q2.enqueue("cv");
	q2.enqueue("lk");
	q2.enqueue("ab");
	q2.print();

	stradix(q2, 2);
	q2.print();

	return 0;
}