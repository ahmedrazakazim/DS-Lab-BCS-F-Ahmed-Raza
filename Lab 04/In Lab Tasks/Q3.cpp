#include <iostream>
using namespace std;

int main() {
   int size;
    cout << "Enter the size of the dataset: ";
   cin >> size;

   int arr[100];
    cout << "Enter " << size << " account balances:\n";
   for(int i=0;i<size;i++)
       cin >> arr[i];

   bool sorted=true;
   for(int i=1;i<size;i++){
       if(arr[i]<arr[i-1]){
         sorted=false;
           break; }
   }

   if(!sorted){
      for(int i=0;i<size-1;i++){
         for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
         }
      }
      cout<<"Data was not sorted. Sorted array applied.\n";
   }

   bool uniform=true;
   int diff=arr[1]-arr[0];
   for(int i=2;i<size;i++){
       if(arr[i]-arr[i-1]!=diff){uniform=false; break;}
   }

   if(!uniform){
       cout<<"Error: Data is not uniformly distributed.\n";
       return 0;
   }

   int target;
        cout<<"Enter the target balance to search for: ";
     cin >> target;

   int low=0, high=size-1, pos=-1;
   while(low<=high && target>=arr[low] && target<=arr[high]){
       int mid = low + ((target - arr[low])*(high-low))/(arr[high]-arr[low]);
       if(arr[mid]==target){
         pos=mid; 
           break;}
       
     if(arr[mid]<target) 
         low=mid+1;
       
       else high=mid-1;
   }

   if(pos!=-1)
         cout<<"Target balance "<<target<<" found at index "<<pos<<endl;
   
   else
       cout<<"Target balance "<<target<<" not found.\n";

   return 0;
}
