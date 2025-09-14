#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int main() {

    int n;
    cout<< "Enter number of people (N): ";
    cin >> n;

    if (n <= 0) return 0;

    int k;
    cout<< "Enter step count (k): ";
    cin    >> k;

    Node* head = new Node(1);
    Node* tail = head;

    for (int i = 2; i <= n; i++) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    tail->next = head; // Make it circular

    Node* prev = tail;
    Node* curr = head;

    while (curr->next != curr) {
        for (int count = 1; count < k; count++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
             delete curr;
        
        curr = prev->next;
    
        
    }

    cout   << "Position of survivor: " << curr->data << endl;

    delete curr;




    return 0;
}
