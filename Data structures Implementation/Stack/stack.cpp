#include <iostream>
#define n 100

using namespace std;

class Stack
{
private:
    int *container;
    int topPtr;
    int sizePtr;

public:
    Stack()
    {
        container = new int[n];
        topPtr = -1;
        sizePtr = 0;
    }

    // push operation
    void push(int x)
    {
        if (topPtr == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        topPtr++;
        sizePtr++;
        container[topPtr] = x;
    }

    // pop operation
    void pop()
    {
        if (topPtr == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        topPtr--;
        sizePtr--;
    }

    // top operation
    int top()
    {
        if (topPtr == -1)
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return container[topPtr];
    }

    // check stack is empty
    bool isEmpty()
    {
        return topPtr == -1;
    }

    // return size of the stack
    int size()
    {
        return sizePtr;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.size() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.push(4);
    cout << s.top() << endl;
    return 0;
}