#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
  
  for (int i = 0; i < n-1; i++)
      {
        for(int j=0;j<n-i-1;j++)
        {
              if (arr[j] > arr[j+1]) 
            {
        int temp = arr[j];
              arr[j]   = arr[j+1]; 
      arr[j+1]   =  temp; 
            }
        }
  }
}

void showArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";  
 cout<<endl; 
}

int main()
{
  int n;
    cout << "Enter number of elements: "; 
 cin >> n;

    int* arr = new int[n]; 
       cout << "Enter " << n << " elements:" << endl;

    for (int i=0;i<n;i++)
      {
   cin>>arr[i];
      }

 cout << "Array before sorting: ";
    showArray(arr,n);

      bubbleSort(arr,n);

    cout<<"Array after sorting: ";
 showArray(arr,n);

  delete[] arr; 
    return 0;
}
