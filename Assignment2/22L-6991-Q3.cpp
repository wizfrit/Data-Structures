#include <iostream>
using namespace std;
template <typename T>
struct node
{
	T data;
	node<T>* next;
	node<T>* prev;

    node()
    {
    data = '\0';
    next = NULL;
    prev = NULL;
    }
};
template <typename T>
class UndoStack
{
	node<T>* top; //lastly added element
    node<T>* tail; // firstly added element
	int size;
    int maxsize = 5;
public:
    UndoStack()
    {
        top = NULL;
        tail = NULL;
        size = 0;
    }
    int Size()
    {
        return size;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    T const& peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            cout << "Stack is Empty \n";
            return '\0';
        }
    }
    void forget() //deleting from the tail or end of the stack
    {
        node<T>* temp = tail;
        tail = tail->prev;
        delete temp;
    }
    void pop() //deleting from the top of stack
    {
        if (!isEmpty())
        {

            node<T>* temp = top;
            top = top->next;
            temp = NULL;
            delete temp;
            size--;
        }
        else
        {
            cout << "Stack is Empty \n";
        }
    }

    void push(const T& e)
    {
        node<T>* temp = new node<T>;
        temp->data = e;
        if (size == 0)
        {
            tail = top = temp;
        }
        else
        {
            temp->next = top;
            top->prev = temp;
            top = temp;   
        }
        size++;
        if (maxsize < size) //if size exceeds 100 than delete the firstly added element
        {
            forget();
            size--;
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void print() //printed using push and pop in opposite direction
    {
        UndoStack<T> tempstack;
        node<T>* temp = top;
        while (!isEmpty())
        {
            tempstack.push(peek());
            cout << peek() << "\t";
            pop();
        }
        cout << endl;
        while (!tempstack.isEmpty())
        {
            push(tempstack.peek());
            tempstack.pop();
        }
    }
    ~UndoStack()
    {
        clear();
    }

};
int main()
{
    UndoStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);
    intStack.push(5);
    intStack.push(6);
    intStack.push(7);
    intStack.push(8);
    intStack.push(9);
    intStack.push(10);
    intStack.push(11);
    intStack.print();

    cout << "\nCalling Pop\n";
    intStack.pop();
    intStack.print();

    intStack.push(13);
    intStack.push(14);
    intStack.push(15);
    intStack.push(17);

    intStack.print();
 
	return 0;
}