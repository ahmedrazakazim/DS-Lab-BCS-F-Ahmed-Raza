#include <iostream>
using namespace std;

class SinglyNode {
public:
    int data;
    SinglyNode* next;
    SinglyNode(int val) : data(val), next(nullptr) {}
};

class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

SinglyNode* createSinglyList(int n) {
    int val;
    cout << "Enter value of node 1: ";
    cin >> val;
    SinglyNode* head = new SinglyNode(val);
    SinglyNode* tail = head;

    for (int i = 2; i <= n; i++) {
    cout << "Enter value of node " << i << ": ";
        cin >> val;
    
    tail->next = new SinglyNode(val);
    tail = tail->next;
    }
    return head;
}

void printSingly(SinglyNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

DoublyNode* convertToDoubly(SinglyNode* head) {
    if (!head) return nullptr;
    DoublyNode* dHead = new DoublyNode(head->data);
DoublyNode* dTail = dHead;
head = head->next;

while (head) {
        DoublyNode* newNode = new DoublyNode(head->data);
        dTail->next = newNode;
        newNode->prev = dTail;
        dTail = newNode;
        head = head->next;
}
    
    
    return dHead;
        }

SinglyNode* convertToCircular(SinglyNode* head) {
    
    if (!head)
    return nullptr;
    
    SinglyNode* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;
    return head;

    
}

void printDoubly(DoublyNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

void printCircular(SinglyNode* head, int n) {
    SinglyNode* temp = head;
    for (int i = 0; i < n; i++) {
        cout << temp->data;
        if (i != n-1) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout<< "Enter number of nodes in singly linked list: ";
    cin  >> n;

    SinglyNode* sList = createSinglyList(n);

    cout << "Original Singly Linked List: ";
    printSingly(sList);

    DoublyNode* dList = convertToDoubly(sList);
    
    cout  << "Converted Doubly Linked List: ";
    printDoubly(dList);

    SinglyNode* cList = convertToCircular(sList);
    
    
      cout << "Converted Circular Linked List: ";
  
    printCircular(cList, n);
    
    
    
    

    return 0;
  
}
