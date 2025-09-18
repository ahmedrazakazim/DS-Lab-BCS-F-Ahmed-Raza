#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key)
{
    int low = 0, high = n-1;

    while(low <= high && key >= arr[low] && key <= arr[high])
    {
        if(low == high) 
        {
            if(arr[low] == key) 
                 return low; 
            return -1; 
        }

        int pos = low + (((double)(high-low) / (arr[high]-arr[low])) * (key - arr[low]));

          if(pos < low || pos > high)
              break;  

        if(arr[pos] == key) 
             return pos; 
        else if(arr[pos] < key)  
              low = pos+1; 
        else
        {
         high = pos - 1;   
        }
    }
   return -1; 
}

int main()
{
   int n, key; 
    cout<<"Enter array size: "; 
    cin>>n;

   int* arr = new int[n]; 
   cout<<"Enter "<<n<<" sorted elements:"<<endl;

   for(int i=0;i<n;i++)
   {
     cin>>arr[i]; 
   }

   cout<<"\nEnter element to search: "; 
   cin>>key; 

   int pos = interpolationSearch(arr,n,key);

   if(pos != -1)
        cout<<"Element "<<key<<" found at index "<<pos;
   else 
    {
        cout<<"Element "<<key<<" not present in array";
    }

   delete[] arr;
   return 0; 
}
