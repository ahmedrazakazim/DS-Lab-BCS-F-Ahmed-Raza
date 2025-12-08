#include <iostream>
#include <string>

using namespace std;

#define BUCKET_COUNT 100

class DataEntry{
    public:
    string recordValue;
    string recordKey;
    DataEntry* nextLink;
    
    DataEntry(string k , string v){
        nextLink = nullptr;
        recordKey = k;
        recordValue = v;
    }
};

class ChainedDictionary{
    DataEntry* bucketArray[BUCKET_COUNT];
    
    public:
    ChainedDictionary(){
        for(int i = 0 ; i < BUCKET_COUNT ; i++){
            bucketArray[i] = nullptr;
        }
    }

    int computeIndex(string key){
        int hashSum = 0;
        for(int i = 0 ; i < key.size() ; i++){
            hashSum += key[i];
        }
        return hashSum % BUCKET_COUNT;
    }

    void insertRecord(string key , string value){
        int index = computeIndex(key);
        DataEntry* current = bucketArray[index];
        
        while(current != nullptr){
            if(current->recordKey == key){
                current->recordValue = value;
                return;
            }
            current = current->nextLink;
        }

        DataEntry* newEntry = new DataEntry(key , value);
        newEntry->nextLink = bucketArray[index];
        bucketArray[index] = newEntry;
    }

    void retrieve(string key){
        int index = computeIndex(key);
        DataEntry* current = bucketArray[index];
        
        while(current != nullptr){
            if(current->recordKey == key){
                cout << "search for " << key << ": " << current->recordValue << endl;
                return;
            }
            current = current->nextLink;
        }
        cout << "Search word not found. " << endl;
    }

    void erase(string key){
        int index = computeIndex(key);
        DataEntry* current = bucketArray[index];
        DataEntry* previous = nullptr;

        if(current == nullptr){
            cout << "key not found for deletion." << endl;
            return ;
        }

        while(current != nullptr && current->recordKey != key){
            previous = current;
            current = current->nextLink;
        }
        
        if(current == nullptr){
            cout << "key not found for deletion." << endl;
            return;
        }

        if(previous == nullptr){
            bucketArray[index] = current->nextLink;
        }
        else{
            previous->nextLink = current->nextLink;
        }
        
        cout << "key " << key << " deleted successfully." << endl;
        delete current;
    }

    void displayAll(){
        for(int i = 0 ; i < BUCKET_COUNT ; i++){
            DataEntry* current = bucketArray[i];
            if(current == nullptr){
                continue;
            }
            cout << "[" << i  << "]" ;
            
            while(current != nullptr){
                cout << "(" << current->recordKey << "," << current->recordValue << ")";
                if (current->nextLink != nullptr) {
                    cout << "->";
                }
                current = current->nextLink;
            }
            cout << endl;
        }
    }
    
    ~ChainedDictionary() {
        for (int i = 0; i < BUCKET_COUNT; ++i) {
            DataEntry* current = bucketArray[i];
            while (current != nullptr) {
                DataEntry* next = current->nextLink;
                delete current;
                current = next;
            }
        }
    }
};

int main(){
    ChainedDictionary dictionary;
    dictionary.insertRecord("AB" ,"FASTNU");
    dictionary.insertRecord("CD" , "CS");
    dictionary.insertRecord("ABC" , "UNI");
    dictionary.insertRecord("ABd" , "KHI");
    dictionary.insertRecord("b" , "aplha");
    
    cout << "--- Initial Table ---" << endl;
    dictionary.displayAll();
    
    cout << endl;
    cout << "Searching for key " << endl;
    dictionary.retrieve("ABd");
    
    cout << endl;
    dictionary.erase("b");
    
    cout << endl;
    cout << "--- Table After Deletion ---" << endl;
    dictionary.displayAll();
    
    return 0;
}
