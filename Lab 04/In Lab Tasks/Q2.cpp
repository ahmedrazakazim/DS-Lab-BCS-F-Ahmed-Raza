#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];
    cout << "Enter " << size << " employee IDs (sorted):\n";
   
  for(int i=0;i<size;i++) 
      cin >> arr[i];

    int roll;
    cout << "Enter your roll number: ";
    cin >> roll;
  
    int lastTwo = roll % 100;

    int left=0, right=size-1, pos=-1;
    while(left<=right){
        int mid=(left+right)/2;
      
        if(arr[mid]%100 == lastTwo){
          pos=mid;
            break;}
          
        else if(arr[mid]%100 < lastTwo)
          left=mid+1;
       
        else right=mid-1;
    }

    if(pos!=-1){
        cout << "Employee ID " << arr[pos] << " found at index " << pos << endl;
    } else {
        pos=left;
        int newID = (arr[0]/100)*100 + lastTwo;
          for(int j=size;j>pos;j--)
            arr[j]=arr[j-1];
      
        arr[pos]=newID;
        size++;
        cout << "Employee ID " << newID << " not found, inserted at index " << pos << endl;
    }

    cout << "Updated array: ";
    for(int i=0;i<size;i++)
      cout << arr[i] << " ";
  
    cout << endl;
    return 0;
}
