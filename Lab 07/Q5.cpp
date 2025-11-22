#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    if (current == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    while (current != nullptr) {
        cout << current->data << (current->next ? " -> " : "");
        current = current->next;
    }
    cout << endl;
}

Node* insert(Node* head, int data) {
    if (!head) {
        return new Node(data);
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
    return head;
}

Node* getTail(Node* current) {
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current;
}


Node* partition(Node* head, Node* tail) {
    if (head == tail || head == nullptr || tail == nullptr) {
        return head;
    }

    int pivot_val = tail->data; 

    Node* i = nullptr; 
    Node* j = head;

    while (j != tail) {
        if (j->data <= pivot_val) {
            if (i == nullptr) {
                i = head; 
            } else {
                i = i->next; 
            }
            
            if (i != j) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
        j = j->next;
    }

    if (i == nullptr) {
        int temp = head->data;
        head->data = tail->data;
        tail->data = temp;
        
        return head;
    } else {
        i = i->next;

        int temp = i->data;
        i->data = tail->data;
        tail->data = temp;
        
        return i;
    }
}

void quickSortLL(Node** head_ref, Node* end) {
    Node* head = *head_ref;
    
    if (head == nullptr || head == end || head->next == end) {
        return;
    }
    
    Node* current_tail = (end == nullptr) ? getTail(head) : end;

    Node* pivot_pos = partition(head, current_tail);
    
    Node* less_end = head;
    while (less_end && less_end->next != pivot_pos) {
        less_end = less_end->next;
    }
    
    Node* greater_start = pivot_pos->next;

    if (less_end != nullptr) {
        less_end->next = nullptr; 
        
        quickSortLL(head_ref, less_end);
        
        Node* sorted_less_tail = *head_ref;
        while (sorted_less_tail->next != nullptr) {
            sorted_less_tail = sorted_less_tail->next;
        }
        sorted_less_tail->next = pivot_pos;
    }

    if (greater_start != nullptr) {
        pivot_pos->next = nullptr;
        
        Node* greater_head = greater_start;
        quickSortLL(&greater_head, current_tail);

        pivot_pos->next = greater_head;
    }
}

void sortList(Node** head_ref) {
    quickSortLL(head_ref, nullptr);
}

int main() {
    Node* head = nullptr;
    
    head = insert(head, 10);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 9);
    head = insert(head, 1);
    head = insert(head, 5);
    head = insert(head, 3);

    cout << "Original Linked List:" << endl;
    printList(head);

    Node* empty_list = nullptr;
    cout << "\nTest Empty List (before sort):" << endl;
    sortList(&empty_list);
    printList(empty_list);

    Node* single_node = new Node(42);
    cout << "\nTest Single Node List (before sort):" << endl;
    printList(single_node);
    sortList(&single_node);
    cout << "Test Single Node List (after sort):" << endl;
    printList(single_node);

    cout << "\nApplying Quicksort to the original list..." << endl;
    sortList(&head);

    cout << "\nSorted Linked List (Expected: 1 -> 3 -> 5 -> 7 -> 8 -> 9 -> 10):" << endl;
    printList(head);
    
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    delete single_node;
    
    return 0;
}
