#include <iostream>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node(string u) {
        url = u;
        next = NULL;
    }
};

class Stack {
private:
      Node* top;

public:
    Stack()
    {
      top = NULL; 
    }

    void visit(string url)
{
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << url << endl;
    }

    void back() {
        if (top == NULL) {
            cout << "No history to go back.\n";
            return;
        }
        cout << "Going back from: " << top->url << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void currentPage()
{
        if (top == NULL)
            cout << "No pages visited yet.\n";

          
        else
            cout << "Current page: " << top->url << endl;
    }

    void showHistory() 
{
        if (top == NULL) {
            cout << "No browsing history.\n";
            return;
      
        }
        cout << "Browsing history:\n";
        Node* temp = top;
      
  while (temp != NULL) {
            cout << temp->url << endl;
            temp = temp->next;
        
        
           }
     
  }
};

int main() {
    Stack browser;
    browser.visit("google.com");
    browser.visit("youtube.com");
    browser.visit("github.com");
    
  browser.currentPage();
    browser.back();
    browser.currentPage();
    browser.showHistory();
}
