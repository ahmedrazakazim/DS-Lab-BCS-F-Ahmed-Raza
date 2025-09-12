#include <iostream>
using namespace std;

int main() {
   int size;
    cout << "Enter the size of the array: ";
   cin >> size;

    int arr[size];
  cout << "Enter " << size << " integers for the array:\n";
   for (int i = 0; i < size; ++i) {
         cin >> arr[i];
     }

   int target;
    cout << "Enter the target value to search for: ";
        cin >> target;

   int index = -1;
     for (int i = 0; i < size; ++i) {
       if (arr[i] == target) {
             index = i;
        break;
       }
     }

    if (index != -1) {
      cout << "Target value " << target << " found at index " << index << "." << endl;
    }    else {
   cout << "Target value " << target << " not found in the array." << endl;
   }

  return 0;
}
