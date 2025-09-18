#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i=1; i<n; i++) 
   {
        int key = arr[i]; 
        int j=i-1;
        
        while(j >=0 && arr[j] > key) 
        {
          arr[j+1] = arr[j];  
              j--; 
        }
     arr[j+1] = key;   
   }
}

int binarySearch(int arr[], int n, int target)
{
   int left = 0; 
    int right = n-1; 

    while(left <= right)
    {
  int mid = left + (right-left)/2;

        if(arr[mid] == target) 
            return mid;
        else if (arr[mid] < target) 
             left = mid+1;
        else 
        {
      right = mid - 1;  
        }
    }
   return -1; 
}

void display(int arr[], int n)
{
   for(int i=0;i<n;i++)
        cout<<arr[i]<<" "; 
 cout<<endl; 
}

int main()
{
  int n;
    cout<<"Enter size of array: "; 
 cin>>n;

   int* arr = new int[n]; 
    cout<<"Enter "<<n<<" numbers:"<<endl;

   for (int i=0;i<n;i++)
   {
       cin>>arr[i];
   }

   cout<<"Unsorted array: ";
   display(arr,n);

       insertionSort(arr,n);

    cout<<"Sorted array: ";
   display(arr,n);

   int target;
   cout<<"\nEnter element to search: ";
   cin>>target;

   int pos = binarySearch(arr,n,target);

   if(pos != -1)
        cout<<"Element "<<target<<" found at index "<<pos<<endl;
   else
    {
      cout<<"Element "<<target<<" not found in the array"<<endl;
    }

  delete[] arr;
  return 0;
}
