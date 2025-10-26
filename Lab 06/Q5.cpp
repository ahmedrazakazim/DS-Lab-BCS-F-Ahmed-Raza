#include <iostream>
#include <string>
using namespace std;

class Stack {
     int top;
     char arr[100];
public:
   Stack(){ top=-1; }
   bool empty(){ return top==-1; }
   void push(char x){ arr[++top]=x; }
   char pop(){ return arr[top--]; }
   char peek(){ return arr[top]; }
};

class IntStack {
  int arr[100];
     int top;
 public:
   IntStack(){ top=-1; }
   void push(int v){ arr[++top]=v; }
   int pop(){ return arr[top--]; }
   bool empty(){ return top==-1; }
   int peek(){ return arr[top]; }
};

int prec(char c){
   if(c=='^') return 3;
 else if(c=='*'||c=='/') return 2;
 else if(c=='+'||c=='-') return 1;
  return -1;
}

string infixToPostfix(string s){
   Stack st;
 string res="";
    for(int i=0; i<s.length(); i++){
      char c=s[i];
       if(isalnum(c)) res+=c;
    else if(c=='(') st.push(c);
 else if(c==')'){
     while(!st.empty() && st.peek()!='(') {
          res+=st.pop();
     }
     st.pop();
 }
 else{
    while(!st.empty() && prec(c)<=prec(st.peek())) {
         res+=st.pop();
    }
   st.push(c);
 }
 }
 while(!st.empty()){ res+=st.pop(); }
 return res;
}

int evalPostfix(string exp){
  IntStack s;
    for(char c:exp){
      if(isdigit(c)) s.push(c-'0');
     else{
        int b=s.pop();
      int a=s.pop();
     int res=0;
     if(c=='+') res=a+b;
   else if(c=='-') res=a-b;
 else if(c=='*') res=a*b;
 else if(c=='/') res=a/b;
 s.push(res);
   }
  }
  return s.pop();
}

int main(){
   string infix="(1+2)*3";
 string postfix=infixToPostfix(infix);
    cout<<"Postfix: "<<postfix<<endl;
 cout<<"Evaluation: "<<evalPostfix(postfix)<<endl;
}
