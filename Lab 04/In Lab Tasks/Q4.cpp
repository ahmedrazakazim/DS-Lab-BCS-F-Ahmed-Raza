//Sorting Task
#include <iostream>
using namespace std;

int main() {
   int arr[10]={5,1,3,6,2,9,7,4,8,10};

   int size=10;
   for(int i=0;i<size-1;i++){
       for(int j=0;j<size-i-1;j++){
           if(arr[j]<arr[j+1]){
               int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp; }
       }
   }

   cout<<"Array sorted in descending order: ";
   for(int i=0;i<size;i++) 
       cout<<arr[i]<<" ";
   cout<<endl;


  

   return 0;
}
