#include <iostream>
// Only iostream is used

using namespace std;

class Node {
public:
    char name[50]; 
    int score;
    Node* next;

    Node(const char* n, int s) : score(s), next(nullptr) {
        // Manual copy of C-string name since <cstring> (for strcpy) is forbidden
        int i = 0;
        while (n[i] != '\0' && i < 49) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }
};

Node* insert(Node* head, const char* name, int score) {
    Node* newNode = new Node(name, score);
    if (!head) {
        return newNode;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->name << " " << current->score << endl;
        current = current->next;
    }
}

Node* countSort(Node* head, int exp) {
    Node* buckets[10] = {nullptr};
    Node* tails[10] = {nullptr};
    
    Node* current = head;
    while (current != nullptr) {
        int index = (current->score / exp) % 10;
        
        Node* next = current->next;
        current->next = nullptr; 
        
        if (buckets[index] == nullptr) {
            buckets[index] = current;
            tails[index] = current;
        } else {
            tails[index]->next = current;
            tails[index] = current;
        }
        
        current = next;
    }

    Node* new_head = nullptr;
    Node* list_tail = nullptr;
    
    for (int i = 0; i < 10; i++) {
        if (buckets[i] != nullptr) {
            if (new_head == nullptr) {
                new_head = buckets[i];
                list_tail = tails[i];
            } else {
                list_tail->next = buckets[i];
                list_tail = tails[i];
            }
        }
    }
    
    return new_head;
}

Node* radixSort(Node* head) {
    for (int exp = 1; exp <= 100; exp *= 10) {
        head = countSort(head, exp);
    }
    return head;
}

// Helper to manually compare C-strings since <cstring> is forbidden
bool areNamesEqual(const char* name1, const char* name2) {
    int i = 0;
    while (name1[i] != '\0' && name2[i] != '\0') {
        if (name1[i] != name2[i]) {
            return false;
        }
        i++;
    }
    return name1[i] == '\0' && name2[i] == '\0';
}

Node* searchRecord(Node* head, const char* searchName, Node** prevNode) {
    Node* current = head;
    *prevNode = nullptr;

    while (current != nullptr) {
        if (areNamesEqual(current->name, searchName)) {
            return current;
        }
        *prevNode = current;
        current = current->next;
    }
    return nullptr;
}

Node* deleteRecord(Node* head, const char* deleteName) {
    Node* prev = nullptr;
    Node* target = searchRecord(head, deleteName, &prev);

    if (target == nullptr) {
        cout << "Record for " << deleteName << " not found. List remains unchanged." << endl;
        return head; 
    }

    if (prev == nullptr) {
        head = target->next;
    } else {
        prev->next = target->next;
    }

    cout << "\nRecord successfully deleted: " << target->name << " " << target->score << endl;
    delete target;
    return head;
}

void cleanup(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Node* head = nullptr;
    
    head = insert(head, "Ayan", 90);
    head = insert(head, "Zameer", 60);
    head = insert(head, "Sara", 70);
    head = insert(head, "Sohail", 30);
    head = insert(head, "Ahmed", 20);
    // Added more inputs for better testing
    head = insert(head, "Jane", 5);
    head = insert(head, "Mike", 100);

    cout << "Initial List of Student Records (Unsorted):" << endl;
    printList(head);

    head = radixSort(head);

    cout << "\nSorted List (by Score in Ascending Order):" << endl;
    printList(head);

    cout << "\n--- Search and Delete Operation ---" << endl;
    
    const char* delete_name1 = "Ahmed";
    head = deleteRecord(head, delete_name1);

    cout << "\nUpdated List (Ahmed deleted):" << endl;
    printList(head);

    const char* delete_name2 = "Sohail";
    head = deleteRecord(head, delete_name2);
    
    cout << "\nUpdated List (Sohail deleted):" << endl;
    printList(head);

    const char* delete_name3 = "NonExistent";
    head = deleteRecord(head, delete_name3);

    cleanup(head);
    
    return 0;
}
