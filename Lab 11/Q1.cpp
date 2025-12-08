#include <iostream>
#include <string>

using namespace std;

const int BUCKET_COUNT = 7;

class KeyValueUnit{
    public:
    string itemKey;
    string itemValue;
    KeyValueUnit* nextLink;
    
    KeyValueUnit(string k , const string& v){
        itemKey = k;
        itemValue = v;
        nextLink = nullptr;
    }
};

class ChainedTable{
    KeyValueUnit* dataArray[BUCKET_COUNT];

    public:
    ChainedTable(){
        for(int i = 0 ; i < BUCKET_COUNT ; i++){
            dataArray[i] = nullptr;
        }
    }

    int generateHash(string key){
        int len = key.size();
        int total = 0;
        for(int i = 0 ; i < len ; i++){
            char c = key[i];
            total += c ;
        }
        return total % BUCKET_COUNT;
    }

    void put(string key , string value){
        int index = generateHash(key);

        KeyValueUnit* current = dataArray[index];
        while(current != nullptr){
            if(current->itemKey == key){
                current->itemValue = value;
                return;
            }
            current = current->nextLink;
        }

        KeyValueUnit* newNode = new KeyValueUnit(key , value);
        newNode->nextLink = dataArray[index];
        dataArray[index] = newNode;
    }

    void display() {
        for(int i = 0 ; i < BUCKET_COUNT ; i++){
            KeyValueUnit* current = dataArray[i];
            if(current == nullptr){
                continue;
            }
            cout << "[" << i << "]: " ;
            
            while(current != nullptr){
                cout << "(" << current->itemKey << " , " << current->itemValue << ") " ;
                current = current->nextLink;
            }
            cout << endl;
        }
    }
    
    ~ChainedTable() {
        for (int i = 0; i < BUCKET_COUNT; ++i) {
            KeyValueUnit* current = dataArray[i];
            while (current != nullptr) {
                KeyValueUnit* next = current->nextLink;
                delete current;
                current = next;
            }
        }
    }
};

int main(){
    ChainedTable myTable;
    myTable.put("A" , "aaaaa");
    myTable.put("B" , "bbbbb");
    myTable.put("C" , "ccccc");
    
    cout << "Initial Traversal:" << endl;
    myTable.display();
    
    cout << "\nAfter updating value:" << endl;
    myTable.put("A" , "zzzzz");
    myTable.display();
    
    return 0;
}
