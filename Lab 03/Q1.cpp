#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int val) {
  
  Node* newNode = new Node{val, nullptr};
  
  if (!head) return newNode;
    Node* temp = head;
  
  while (temp->next) 
    temp = temp->next;
    
  temp->next = newNode;
    return head;
}

bool isPalindrome(Node* head) {

  if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* prev = nullptr;
    Node* curr = slow;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    Node* first = head;
    Node* second = prev;
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
  
    Node* head = nullptr;
    int n, val;
    cout << "Enter number of nodes: ";
      cin >> n;
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }

    if (isPalindrome(head))
        cout << "The list is a palindrome\n";
    else
        cout << "The list is not a palindrome\n";



    return 0;
}
