#include <iostream>

using namespace std;

class Node {
    public:    
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int val) {
  
  Node* newNode = new Node{val, nullptr};
  
    if (!head)
      return newNode;
  
    Node* temp = head;

    while (temp->next) temp = temp->next;
    temp->next = newNode;
    
  
  return head;

}

void printList(Node* head) {
    while (head!=NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
  
}

Node* mergeSortedLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = nullptr;
    Node* tail = nullptr;

    if (a->data < b->data) {
        head = a;
        a = a->next;
      }  
    else {
        head = b;
        b = b->next;
      }
      tail = head;

    while (a && b) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a) tail->next = a;
    if (b) tail->next = b;

    return head;
}

int main() 
{
    Node* listA = nullptr;
    Node* listB = nullptr;

    int n, m, val;
    cout << "Enter number of nodes in List A: ";
    cin >> n;
    cout << "Enter " << n << " integers (sorted):\n";

  for (int i = 0; i < n; i++) {
        cin >> val;
        listA = insertEnd(listA, val);
      }

    cout << "Enter number of nodes in List B: ";
        cin >> m;
      cout << "Enter " << m << " integers (sorted):\n";
    for (int i = 0; i < m; i++) {
        cin >> val;
          listB = insertEnd(listB, val);
        }  

    Node* merged = mergeSortedLists(listA, listB);

    cout << "Merged List: ";
    printList(merged);


  
    return 0;
}
