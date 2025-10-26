#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
  int arr[SIZE];
  int front , rear;
  
public:
CircularQueue() {  
  front=-1;
  rear=-1;
}

bool isFull() {
     return (front==0 && rear==SIZE-1) || (rear+1)%SIZE==front;
}
bool isEmpty() {   return front==-1;   }

void enqueue(int val) {
  if(isFull()) { cout<<"Queue Overflow\n";  return; }
     if(front==-1) front=0;
   rear=(rear+1)%SIZE;
        arr[rear]=val;
}

void dequeue() {
   if(isEmpty()) { cout<<"Queue Underflow\n"; return; }
     cout<<"Dequeued: "<<arr[front]<<endl;
   if(front==rear) { front=rear=-1; }
     else front=(front+1)%SIZE;
}

void display() {
   if(isEmpty()) { cout<<"Queue Empty\n"; return; }
      cout<<"Queue: ";
 
  int i=front;
  
  while(true) {
        cout<<arr[i]<<" ";
          if(i==rear) break;
       i=(i+1)%SIZE;
  
  }
   cout<<endl;

}


};

int main() {
   CircularQueue q;
 q.enqueue(10);
 q.enqueue(20);
 q.enqueue(30);
q.dequeue();
q.enqueue(40);
q.enqueue(50);

q.display();
q.enqueue(60);
q.dequeue();
q.display();
}
