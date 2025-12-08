#include <iostream>
using namespace std;

#define TABLE_SIZE 100

class Node{
    public:
    string value;
    string key;
    Node* next;
    Node(string k , string v){
        next = NULL;
        key = k;
        value = v;
    }
};

class HashTable{
    Node* Table[TABLE_SIZE];
    public:
    HashTable(){
        for(int i = 0 ; i < TABLE_SIZE ; i++){
            Table[i] = nullptr;
        }
    }

    int hashfunction(string key){
        int sum = 0;
        for(int i = 0 ; i < key.size() ; i++){
            sum += key[i];
        }
        return sum % TABLE_SIZE;
    }

    void add_record(string key , string value){
        int index = hashfunction(key);
        Node* temp = Table[index];
        while(temp != NULL){
            if(temp->key == key){
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        Node* newnode = new Node(key , value);
        newnode->next = Table[index];
        Table[index] = newnode;
    }

    void search(string key){
        int index = hashfunction(key);
        Node* temp = Table[index];
        while(temp != NULL){
            if(temp->key == key){
                cout << "search for " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Search word not found. " << endl;
    }

    void remove(string key){
        int index = hashfunction(key);
        Node* temp = Table[index];
        Node* prev = nullptr;

        if(temp == NULL){
            cout << "key not found for deletion." << endl;
            return ;
        }

        while(temp != NULL & temp->key != key){
            prev = temp;
            temp = temp->next;
        }
        if(temp->key == key){
            Table[index] = temp->next;
        }
        else{
            prev->next = temp->next;
        }
        cout << "key " << key << " deleted successfully." << endl;
        delete temp;

    }

    void traverse(){
        for(int i  = 0 ; i < TABLE_SIZE ; i++){
            Node* temp = Table[i];
            if(temp == NULL){
                continue;
            }
            cout << "[" << i  << "]" ;
            while(temp != NULL){
                cout << "(" << temp->key << "," << temp->value << ")";
                Node* curr = temp->next;
                while(curr != NULL){
                    cout  << "->";
                    cout << "(" << temp->key << "," << temp->value << ")" ;
                    curr = curr->next;
                } 
                cout << endl;
                temp = NULL;
            }
        }
    }

};

int main(){
    HashTable table;
    table.add_record("AB" ,"FASTNU");
    table.add_record("CD" , "CS");
    table.add_record("ABC" , "UNI");
    table.add_record("ABd" , "KHI");
    table.add_record("b" , "aplha");
    table.traverse();
    cout << endl;
    cout << "Searching for key " << endl;
    table.search("ABd");
    cout << endl;
    table.remove("b");
    cout << endl;
    table.traverse();
    return 0;


}
