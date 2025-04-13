#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    bool flag = false; // to check if array is flipped or not
    int x = 1; // count to assign flag
    int num = 0;//number of enteries
    int top = 0; // last input
    int tail = 0; // first input
    int size; // total size
    T* arr = new T[size];
public:
    Stack()
    {
        size = 0;
        arr = new T[size];
    }
    Stack(int s)
    {
        size = s;
        arr = new T [size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = '\0';
        }
    }
    bool isFull()
    {
        if ((size) == num)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (num == 0)
            return true;
        else
            return false;
    }
 
    T const& peek()
    {
        if (!isEmpty())
        {
            return arr[top-1];
        }
        else
        {
            cout << "Stack is Empty \n";
            return '\0';
        }
    }
    void pop()
    {
        if (flag)
        {
            arr[top] = '\0';
            top++;
        }
        else if (!isEmpty())
        {
                arr[top - 1] = '\0';
                top--;
        }
        num--;
    }
    void push(const T& e)
    {
        if (flag)
        {
            arr[top-1] = e;
            top--;
        }
        else
        {
            arr[top] = e;
            top++;
        }
        num++;
    }

    ////Basic Stack Functions End here

    void flipStack() //For flipping the stack
    {
        x++;
        int temp = top;
        top = tail;
        tail = temp;
        if (x % 2 == 0) //flipped array will be printed on even count
        {
            flag = true;
        }
        else //original array will be printed on odd count
            flag = false;
    }
    int getsize()
    {
        return size;
    }
    void clear()
    {
        while(!isEmpty())
        {
            pop();
        }
        delete[] arr;
        arr = NULL;
    }
    void print()
    {
        if (flag)
        {
            for (int i = tail-1; i >= top; i--)
            {
                cout << arr[i] << "\t";
            }
        }
        else
        {
            for (int i = tail; i < top; i++)
            {
                cout << arr[i] << "\t";
            }
        }
        cout << endl;
    }
    void sizechange()
    {

        if (flag == false && !isEmpty() && isFull()) // if array if filled completely then doubling its size
        {
            int newsize = size * 2;
            T* temp = new T[newsize];

            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
                arr[i] = NULL;
            }
            size = newsize;

            arr = temp;
            temp = NULL;

        }
        if (flag == true && !isEmpty() && isFull()) // if array if filled completely then doubling size of flipped array
        {
            int newsize = size * 2;
            T* temp = new T[newsize];

            for (int i = tail; i >= top; i--)
            {
                temp[i] = arr[i];
                arr[i] = NULL;
            }
            size = newsize;

            arr = temp;
            temp = NULL;

        }
        else if (size == 1) // because half of 1 would be zero and 0 sized array won't work
        {
            return;
        }
        else if ((size/2) > num ) // if array is less than half filled then reducing the size to half
        {
            size = size / 2;
            T* temp = new T[size];
            
            for (int i = tail; i >= top; i--)
            {
                temp[i] = arr[i];
                arr[i] = NULL;
            }
            arr = temp;

            temp = NULL;
        }
    }
    ~Stack()
    {
        clear();
    }
};

int main()
{
    int size = 1;
    Stack <int> intStack(size);
    if (intStack.getsize() != 0)
    {
        intStack.sizechange();
        cout << "Size : " << intStack.getsize();
        intStack.push(1);
        intStack.sizechange();
        cout << "\nSize : " << intStack.getsize();
        intStack.push(2);
        intStack.sizechange();
        cout << "\nSize : " << intStack.getsize();
        intStack.push(5);
        intStack.sizechange();
        cout << "\nSize : " << intStack.getsize();
        intStack.push(6);
        intStack.sizechange();
        cout << "\nSize : " << intStack.getsize();
        intStack.push(7);
        intStack.sizechange();
        cout << "\nSize : " << intStack.getsize();

        cout << endl;
        intStack.print();
        cout << "Flipped Stack\n";
        intStack.flipStack();
        intStack.print();

        intStack.pop();
        intStack.pop();
        cout << "Pop in stack \n";
        intStack.print();
        intStack.sizechange();
        cout << "Size : " << intStack.getsize();
        cout << endl;
        intStack.print();
        intStack.push(45);
        intStack.sizechange();
        intStack.print();

        cout << "Flipped Stack\n";
        intStack.flipStack();
        intStack.print();
        intStack.push(89);
        intStack.print();
        intStack.pop();
        intStack.print();
    }
    else
    cout << "Size is ZERO\n";
    return 0;
}