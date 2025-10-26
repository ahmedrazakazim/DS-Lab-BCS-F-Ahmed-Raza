#include <iostream>
using namespace std;

#define SIZE 5

class Queue 
{
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue()
{
        front = -1;
        rear = -1;
    }

    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(int x) 
{
        if (isFull())
            cout << "Queue Overflow\n";

          
        else
        {
            if (front == -1)
                front = 0;
          
            arr[++rear] = x;
            cout << "Enqueued: " << x << endl;
        }
    }

    void dequeue() {
        if (isEmpty())
            cout << "Queue Underflow"<<endl;
          
        else
        {
            cout << "Dequeued: " << arr[front] << endl;
            front++;
        }
    }

    void display() {
        if (isEmpty())
            cout << "Queue is empty\n";
        else {
            cout << "Queue contents: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
       
        }
      }
};

int main() {
  
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
  
    q.dequeue();
    q.display();
}
