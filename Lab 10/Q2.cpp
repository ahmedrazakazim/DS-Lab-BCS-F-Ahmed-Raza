#include <iostream>

using namespace std;

bool isHeap(int arr[], int n) {
    
    for (int i = 0; i <= (n - 2) / 2; i++) {  
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left])
            return false;

        if (right < n && arr[i] < arr[right])
            return false;
    }

    return true;
}


void heapifySort(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifySort(arr, n, largest);
    }
}

void heapSortAscending(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifySort(arr, n, i);
    }

    
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);    
        heapifySort(arr, i, 0); 
    }
}



int main() {

int arr[] = {8,7, 6 ,5 ,4};
cout << (isHeap(arr,5) ? "Yes" : "No");

heapSortAscending(arr,5);

cout << "\n";
for (int i : arr){
    cout << i << " ";
}





    return 0;
}
