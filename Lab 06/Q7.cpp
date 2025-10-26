#include <iostream>
using namespace std;

struct Process { int id , priority; };

class Queue {
  Process arr[50]; int front,rear;
  public:
    Queue(){ front=rear=-1; }
   bool empty(){ return front==-1; }
   void enqueue(Process p){
     if(front==-1) front=0;
     arr[++rear]=p;
   }
   Process dequeue(){
      Process p=arr[front];
        if(front==rear) front=rear=-1;
       else front++;
      return p;
   }
};

class Stack 
{
   Process arr[50]; int top;
  public:
   Stack(){ top=-1; }
  bool empty(){ return top==-1; }
  void push(Process p){ arr[++top]=p; }
  Process pop(){ return arr[top--]; }
};

int main(){
    Queue q; Stack s;
   q.enqueue({1,3});
      q.enqueue({2,1});
    q.enqueue({3,2});

   cout<<"Jobs in Queue:\n";
   while(!q.empty()){
     Process p=q.dequeue();
       cout<<"Process "<<p.id<<" priority "<<p.priority<<endl;
     if(p.priority>1) s.push(p);
   }
  

  cout<<"\nExecuting from Stack:\n";
    while(!s.empty()) 
    {
       Process p=s.pop();
         cout<<"Executing Process "<<p.id<<" with Priority "<<p.priority<<endl;
    
    
    }

return 0;
}
