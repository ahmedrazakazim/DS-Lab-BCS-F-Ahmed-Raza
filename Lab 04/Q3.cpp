#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
  int minIndex; 

    for(int i=0; i<n-1; i++)   
   {
        minIndex = i; 
        for (int j = i+1; j < n; j++)
        {
       if(arr[j] < arr[minIndex])
                minIndex = j; 
        }

        if (minIndex != i)
        {
   int temp = arr[minIndex]; 
                arr[minIndex] = arr[i]; 
         arr[i]= temp;   
        }
   }
}

void display(int arr[], int n)
{
   for (int i=0;i<n;i++)
        cout << arr[i] <<" "; 
    cout<<endl;
}

int main()
{
    int n;
 cout<<"Enter array size: ";
    cin >> n;

    int* arr = new int[n]; 
      cout<<"Enter "<<n<<" elements:"<<endl;

    for(int i = 0; i < n; i++)
    {
   cin >> arr[i];
    }

    cout<<"Array before sorting: ";
 display(arr,n);

        selectionSort(arr,n);

    cout<<"Array after sorting: ";
    display(arr,n);

   delete[] arr;
 return 0;
}
