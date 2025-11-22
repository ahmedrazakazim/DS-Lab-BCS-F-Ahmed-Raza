#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int findKthLargest(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        return -1;
    }
    
    insertionSort(arr, n);
    
    return arr[k - 1];
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i < n - 1 ? ", " : "");
    }
    cout << endl;
}

int main() {
    const int N1 = 7;
    int arr1[N1] = {1, 23, 12, 9, 30, 2, 50};
    int K1 = 3;

    cout << "Input Array 1: ";
    printArray(arr1, N1);
    cout << "K: " << K1 << endl;

    int result1 = findKthLargest(arr1, N1, K1);
    cout << "Output: " << result1 << endl;
    
    const int N2 = 5;
    int arr2[N2] = {12, 3, 5, 7, 19};
    int K2 = 2;

    cout << "\nInput Array 2: ";
    printArray(arr2, N2);
    cout << "K: " << K2 << endl;

    int result2 = findKthLargest(arr2, N2, K2);
    cout << "Output: " << result2 << endl;

    const int N3 = 6;
    int arr3[N3] = {10, 5, 10, 20, 15, 20};
    int K3 = 1;

    cout << "\nInput Array 3: ";
    printArray(arr3, N3);
    cout << "K: " << K3 << endl;

    int result3 = findKthLargest(arr3, N3, K3);
    cout << "Output: " << result3 << endl;
    
    return 0;
}
