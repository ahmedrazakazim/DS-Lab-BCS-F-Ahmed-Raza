#include <iostream>

using namespace std;

void swapInts(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swapInts(arr[i], arr[largest]);

        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int N = 10;
    int minHeapArray[N] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    cout << "Input (Min Heap Array): ";
    printArray(minHeapArray, N);

    buildMaxHeap(minHeapArray, N);

    cout << "Output (Max Heap Array): ";
    printArray(minHeapArray, N);
    
    return 0;
}
