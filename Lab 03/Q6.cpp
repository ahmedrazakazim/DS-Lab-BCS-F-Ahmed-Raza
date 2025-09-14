#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};


Node* flattenList(Node* head) {

    Node* curr = head;

    while (curr) {

        if (curr->child) {

            Node* tempNext = curr->next;
            curr->next = curr->child;

            Node* childTail = curr->child;
            while (childTail->next) childTail = childTail->next;

            childTail->next = tempNext;

            curr->child = nullptr;
        }

        curr = curr->next;
    }

    return head;
}


void printList(Node* head) {

    while (head) {

        cout     << head->data;
        if (head->next) cout  << " -> ";
        head = head->next;
    }

  cout    << endl;
}



int main() {

    int n;
cout   << "Enter number of nodes in main list: ";

  cin >> n;

    if (n <= 0) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 1; i <= n; i++) {

        int mainVal;
        cout    << "Enter value of node " << i << ": ";
        cin     >> mainVal;
        Node* newNode = new Node(mainVal);
        if (!head) { head = newNode; tail = newNode; }
        else { tail->next = newNode; tail = newNode; }

        char hasChild;
        cout     << "Does node " << i << " have a child list? (y/n): ";
        cin      >> hasChild;
        if (hasChild == 'y' || hasChild == 'Y') {
            int m;
            cout      << "Enter number of nodes in child list: ";
            cin       >> m;
            Node* cHead = nullptr;
            Node* cTail = nullptr;
            for (int j = 1; j <= m; j++) {
                int childVal;
                cout       << "Enter value of child node " << j << ": ";
                cin        >> childVal;
                Node* cNode = new Node(childVal);
                if (!cHead) { cHead = cNode; cTail = cNode; }
                else { cTail->next = cNode; cTail = cNode; }
            }
            tail->child = cHead;
        }
    }

    cout  << "Original Multilevel List entered" << endl;

    head = flattenList(head);

    cout<< "Flattened List: ";
    printList(head);


  
    return 0;

  
}
