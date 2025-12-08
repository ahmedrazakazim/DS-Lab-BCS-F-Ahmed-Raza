#include <iostream>

using namespace std;

#define BUCKET_COUNT 100
#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 100

class DataEntry{
    public:
    char recordValue[MAX_VAL_LEN];
    char recordKey[MAX_KEY_LEN];
    DataEntry* nextLink;
    
    DataEntry(const char* k , const char* v){
        nextLink = NULL;
      
        int i = 0;
        while ((recordKey[i] = k[i]) != '\0') i++;
        i = 0;
        while ((recordValue[i] = v[i]) != '\0') i++;
    }
    
    
    int compareKeys(const char* s1, const char* s2){
        while(*s1 && (*s1 == *s2)){
            s1++;
            s2++;
        }
        return *(const unsigned char*)s1 - *(const unsigned char*)s2;
    }

    void copyValue(const char* source){
        int i = 0;
        while ((recordValue[i] = source[i]) != '\0') i++;
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

    int computeHashIndex(const char* key){
        int hashSum = 0;
        int i = 0;
        while(key[i] != '\0'){
            hashSum += key[i];
            i++;
        }
        return hashSum % BUCKET_COUNT;
    }

    void insertRecord(const char* key , const char* value){
        int index = computeHashIndex(key);
        DataEntry* current = bucketArray[index];
        
        while(current != nullptr){
            if(current->compareKeys(current->recordKey, key) == 0){
                current->copyValue(value);
                return;
            }
            current = current->nextLink;
        }

        DataEntry* newEntry = new DataEntry(key , value);
        newEntry->nextLink = bucketArray[index];
        bucketArray[index] = newEntry;
    }

    void retrieve(const char* key){
        int index = computeHashIndex(key);
        DataEntry* current = bucketArray[index];
        
        while(current != nullptr){
            if(current->compareKeys(current->recordKey, key) == 0){
                cout << "search for " << current->recordKey << " : " << current->recordValue << endl;
                return;
            }
            current = current->nextLink;
        }
        cout << "Word not found. " << endl;
    }

    void erase(const char* key){
        int index = computeHashIndex(key);
        DataEntry* current = bucketArray[index];
        DataEntry* previous = nullptr;

        if(current == nullptr){
            cout << "key not found for deletion." << endl;
            return ;
        }

        while(current != nullptr && current->compareKeys(current->recordKey, key) != 0){
            previous = current;
            current = current->nextLink;
        }
        
        if(current == nullptr){
            cout << "key not found for deletion." << endl;
            return;
        }
        
        const char* deletedKey = current->recordKey; 

        if(previous == nullptr){
            bucketArray[index] = current->nextLink;
        }
        else{
            previous->nextLink = current->nextLink;
        }
        
        cout << "key " << deletedKey << " deleted successfully." << endl;
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
