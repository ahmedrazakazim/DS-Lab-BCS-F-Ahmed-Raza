#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[100];
    int size;

    MaxHeap() {
        size = 0;
    }

    
    void buildHeap(int a[], int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }

        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }


    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds\n";
            return;
        }

        int old = arr[i];
        arr[i] = new_val;

      
  if (new_val > old)
   {
            while (i != 0 && arr[parent(i)] < arr[i])
             {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
 else
  { 
            
            heapify(i);
        }
    }

    
    void delete_key(int i) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds\n";
            return;
        }

        arr[i] = arr[size - 1];  
        size--;

       
        heapify(i);
    }
    void delete_root() {
        if (size <= 0) {
            cout << "Heap empty\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
 {
MaxHeap h;
int values[] = {8, 7, 6, 5, 4};
h.buildHeap(values, 5);

cout << "Initial Heap: ";
h.printHeap();
h.update_key(3, 10);
cout << "After update index 3 to 10: ";
h.printHeap();
h.delete_root();
cout << "After deleting root: ";
h.printHeap();


   
return 0;
}
