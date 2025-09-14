#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseKGroup(Node* head, int k) {
    
    Node* curr = head;
    Node* prev = NULL;
    
  Node* next = NULL;
      int count = 0;

    Node* temp = head;
  
  for (int i = 0; i < k; i++) {
        if (!temp)   return head; 
        temp = temp->next;
    }

    
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next) {
        head->next = reverseKGroup(next, k);
    }

    return prev; 
}


void printList(Node* head) {
    
    while (head) {
        
        cout   <<  head->data;
        if (head->next)    cout   << " -> ";
        head = head->next;
    }
    cout << endl;


}



int main() {
    
    int n;   
    cout   << "Enter number of nodes: ";
    cin   >> n;

    if (n <= 0) return 0;

    int val;   
    cout   << "Enter value of node 1: ";
    cin   >> val;
    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 2; i <= n; i++) {
        cout  << "Enter value of node " << i << ": ";
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    int k;   
       cout << "Enter group size k: ";
  cin   >> k;

      cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout   << "Reversed in Groups of " << k << ": ";
    printList(head);


  
    return 0;
}
