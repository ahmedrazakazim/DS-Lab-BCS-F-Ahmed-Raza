#include <iostream>
#include <string>

using namespace std;

#define HASH_TABLE_SIZE 100

struct PairData {
    int val1;
    int val2;
};

struct HashNode {
    int keySum;
    PairData pair;
    HashNode* nextLink;
    
    HashNode(int sum, int v1, int v2) {
        keySum = sum;
        pair.val1 = v1;
        pair.val2 = v2;
        nextLink = nullptr;
    }
};

class PairHashTable {
    HashNode* buckets[HASH_TABLE_SIZE];

    public:
    PairHashTable() {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
            buckets[i] = nullptr;
        }
    }

    int hashFunction(int sum) {
        return abs(sum) % HASH_TABLE_SIZE;
    }

    void insertPair(int sum, int v1, int v2) {
        int index = hashFunction(sum);
        HashNode* newNode = new HashNode(sum, v1, v2);
        newNode->nextLink = buckets[index];
        buckets[index] = newNode;
    }
    
    HashNode* searchSum(int sum) {
        int index = hashFunction(sum);
        HashNode* current = buckets[index];
        while (current != nullptr) {
            if (current->keySum == sum) {
                return current;
            }
            current = current->nextLink;
        }
        return nullptr;
    }
    
    ~PairHashTable() {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
            HashNode* current = buckets[i];
            while (current != nullptr) {
                HashNode* next = current->nextLink;
                delete current;
                current = next;
            }
        }
    }
};

void findEqualSumPairs(int arr[], int size) {
    PairHashTable sumMap;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int sum = arr[i] + arr[j];
            HashNode* existingNode = sumMap.searchSum(sum);
            
            if (existingNode != nullptr) {
                PairData p = existingNode->pair;
                
                
                if (p.val1 != arr[i] && p.val1 != arr[j] && p.val2 != arr[i] && p.val2 != arr[j]) {
                    cout << "(" << p.val1 << " + " << p.val2 << ") = (" << arr[i] << " + " << arr[j] << ")" << endl;
                    return;
                }
            }
            else {
                sumMap.insertPair(sum, arr[i], arr[j]);
            }
        }
    }
    cout << "No Pairs Found!" << endl;
}

int main()
{

    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int size1 = 7;
    
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int size2 = 6;
    
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int size3 = 7;

    cout << "Test 1: ";
    findEqualSumPairs(arr1, size1);

    cout << "Test 2: ";
    findEqualSumPairs(arr2, size2);

    cout << "Test 3: ";
    findEqualSumPairs(arr3, size3);
    
    return 0;
}
