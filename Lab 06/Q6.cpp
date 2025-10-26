#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Stack {
   char arr[100];
   int top;
 public:
   Stack()
    {
      top=-1;
}
   bool empty(){ return top==-1; }
   void push(char c){ arr[++top]=c; }
   char pop(){ return arr[top--]; }
   char peek(){ return arr[top]; }
};

class IntStack {
  int arr[100];
  int top;
 public:
   IntStack(){ top=-1; }
   void push(int x){ arr[++top]=x; }
   int pop(){ return arr[top--]; }
   bool empty(){ return top==-1; }
};

int prec(char c){
 if(c=='^') return 3;
 else if(c=='*'||c=='/') return 2;
 else if(c=='+'||c=='-') return 1;
 return -1;
}

string infixToPrefix(string inf){
   reverse(inf.begin(),inf.end());
   Stack st; string res="";
   for(int i=0;i<inf.length();i++){
     char c=inf[i];
    if(isalnum(c)) res+=c;
   else if(c==')') st.push(c);
  else if(c=='('){
    while(!st.empty() && st.peek()!=')'){
       res+=st.pop();
    }
    st.pop();
  }
  else{
     while(!st.empty() && prec(c)<prec(st.peek())){
         res+=st.pop();
     }
     st.push(c);
  }
     
   }
   while(!st.empty()) res+=st.pop();
   reverse(res.begin(),res.end());
   return res;


}

int evalPrefix(string exp){

  IntStack s;
  for(int i=exp.length()-1; i>=0; i--){
     char c=exp[i];
  
    if(isdigit(c)) s.push(c-'0');
   else
    {
       int a=s.pop();
      int b=s.pop();
    int r=0;
   if(c=='+') r=a+b;
 else if(c=='-') r=a-b;
     else if(c=='*') r=a*b;
     else if(c=='/') r=a/b;
 s.push(r);
  
    }
  
  }

  
  
  return s.pop();


}

int main(){
  string infix="(1+2)*3";
  string prefix=infixToPrefix(infix);
  
  cout<<"Prefix: "<< prefix << endl;
  cout<<"Evaluation: " << evalPrefix(prefix) << endl;
}
