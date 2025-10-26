#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() 
{
      top = -1;
}

    void push(int x) {
        if (top == SIZE - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = x;
    }

    void pop()
{
        if (top == -1)
            cout << "Stack Underflow\n";
        else
            top--;
    }

    void peek()
{
        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << arr[top] << endl;
    }

    void display() 
{
        if (top == -1)
            cout << "Stack is empty\n";
        else 
        {
            cout << "Stack contents: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
  
  Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    
    s.peek();
    s.pop();
    s.display();



  return 0;
}
