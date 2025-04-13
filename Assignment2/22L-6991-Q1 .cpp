#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
template <typename T>
struct node
{
	T data;
    node<T>* next;
public:
    node()
    {
    next = NULL;
    }
};
template <class T>
class Stack
{
    node<T>* head;
public:
    Stack()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    T peek()
    {
        if (!isEmpty())
        {
            return head->data;
        }
        else
        {
            cout << "Stack is Empty \n";
        }
    }
    void pop() //deleting from the top of stack
    {
        if (!isEmpty())
        {

            node<T>* temp = head;
            head = head->next;
            temp = NULL;
            delete temp;
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
        if (isEmpty())
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;   
        }
    }

    void clear()
    {
        while (head != NULL)
        {
            node<T>* current = head;
            head = head->next;
            delete current;
        }
    }

    void print() //printed using push and pop in opposite direction
    {
        Stack<T> tempstack;
        node<T>* temp = head;
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
    ~Stack()
    {
        clear();
    }

};
class XMLdata
{
public:
    string s;
    int linenum;
public:
    XMLdata()
    {
        s = '\0';
        linenum = 0;
    }
    XMLdata(string line,int ln):s(line),linenum(ln){}
    
    string gets()
    {
        return s;
    }
    int getlinenum()
    {
        return linenum;
    }
    ~XMLdata()
    {

    }

};
string substring(string str, int index, int len)
{
    string mystring;
    int in = 0;
    while (in != len)
    {
        mystring[in] = str[index];
        index++;
        in++;
    }
    return mystring;
}
int searchindex(string s,char tofind )
{
    int index = 0;
    int size = s.size();
    while (size > 0)
    {
        if (s[index] == tofind)
            break;
        else
        {
            index++;
            size--;
        }
        return index;
    }
}
int main()
{
    Stack<XMLdata> Stck;
    int linecount = 1;
    bool error = false;
    
    ifstream fin; 
    fin.open("test.txt");

    while (!fin.eof()) //will check line by line
    {
        string temp;  //Inputting the line and storing in temp
        getline(fin, temp, '\n');
        int tempsize = temp.size();

        //Checks for < and > 
        if (temp[0] != '<' && temp[tempsize - 1] == '>')
        {
            cout << "Error Attribute\nMissing < at the start of line : " << linecount << endl;
            error = true;
        }
        if (temp[0] == '<' && temp[tempsize - 1] != '>')
        {
            cout << "Error Attribute\nMissing > at the end of line : " << linecount << endl;
            error = true;
        }
        if (temp[0] != '<' && temp[tempsize - 1] != '>')
        {
            cout << "Error Attribute\nMissing < and > at the start and end of line : " << linecount << endl;
            error = true;
        }
        if (linecount == 1) //check for prolog
        {
            int x = 0;
            int y = 0;
            int num = 0;
            for (int i = 0; i < tempsize; i++)
            {
                if (temp[i] == '\"' || temp[i] == '\'')
                {
                    num++;
                }
            }
            if (num % 2 == 1)
            {
                cout << "Error Attribute\nMissing Quote at line : " << linecount << endl;
                x++;
                error = true;
            }
            if (temp[1] == '?' && temp[tempsize - 2] == '?')
            {
                y++;
            }
            if (y == 0)
            {
                cout << "Prolog is Invalid\n";
                error = true;
            }
            linecount++;
            continue;

        }
        if ((temp[searchindex(temp, '>') - 1] == '-') && (temp[searchindex(temp, '>') - 2] == '-')) //condition for comment if start is incorrect
        {
            if (temp[2] == '!' && temp[3] == '-' && temp[4] == '-')
            {
                linecount++;
                continue;
            }
            else
            {
                cout << "Comment Error\nIncorrect Start at line : " << linecount << endl;
                linecount++;
                error = true;
                continue;
            }
        }
        if (temp[2] == '!' && temp[3] == '-' && temp[4] == '-') //condition for comment if end is incorrect
        {
            if ((temp[searchindex(temp, '>') - 1] == '-') && (temp[searchindex(temp, '>') - 2] == '-'))
            {
                linecount++;
                continue;
            }
            else
            {
                cout << "Comment Error\nIncorrect End at line : " << linecount << endl;
                linecount++;
                error = true;
                continue;
            }
        }
        if (linecount != 0) //condition for attributes and tags 
        {
            int num = 0;
            for (int i = 0; i < tempsize; i++) //for attributes same as for prolog
            {
                if (temp[i] == '\"')
                {
                    num++;
                }

            }
            if (num % 2 == 1)
            {
                cout << "Error Attribute\nMissing Quote at line : " << linecount << endl;
                linecount++;
                error = true;
            }
            if (temp[1] != '/') //if not the ending tag,then must be starting tag
            {
                int i = 0;

                while (temp[i] != '>' && temp[i] != ' ' && temp[i] != '\0')
                {
                    i++;
                }
                i--;
                string s1 = temp.substr(1, i);
                XMLdata x1(s1, linecount);
                Stck.push(x1);    //pushing the starting tag of the line
            }
            bool flagpop = false;
            int  popstart = 1;
            for (int i = 0; i < tempsize; i++)
            {
                popstart++;
                if (temp[i] == '<' && temp[(i + 1)] == '/')
                {
                    flagpop = true;
                    break;
                }
            }
            if (flagpop == true) //if ending tag is there,then matching it and poping the stack
            {
                int j = 0;
                for (int i = popstart; temp[i] != '>' && i < tempsize; i++)
                {
                    j++;
                }
                string s1 = temp.substr(popstart, j);
                XMLdata x1(s1, linecount);
                if (s1 == Stck.peek().s)
                {
                    Stck.pop();
                }
            }
        }
            linecount++;
    }
    if (!Stck.isEmpty()) //check if stack is not Empty
    {
        error = true;
        cout << "Tag Error \n" << Stck.peek().s << " at line : " << Stck.peek().linenum << endl;
    }
    if (!error) // If there's any error then,it won't print
    {
        cout << "XML File is perfectly fine\n";
    }

    return 0;
}