#include <iostream>
using namespace std;

int searchElement(int arr[], int n, int key) 
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
  }

int main() 
{
    int n, key;
      cout << "Enter number of elements: ";
    
  cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Value to search: ";
    cin >> key;

    int pos = searchElement(arr, n, key);

    if (pos != -1)
    {
        cout << "Found " << key << " at index " << pos;
    } 
    else
    {
        cout << key << " not present in the array.";
      }

    delete[] arr;
    return 0;
}
