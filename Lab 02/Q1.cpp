#include <iostream>

using namespace std;

int main() {

int *ptr;
int size;
int value;
cout << "Enter the size of your array: " <<endl;
cin>> size;

ptr = new int[size];

for (int i=0; i<size;i++){
    ptr[i]=0;
}

cout << "Enter values to update array: " <<endl;
for (int i=0;i<size;i++) {
    cin >> value;
ptr[i]=value;
}
cout << " { ";
for (int i=0;i<size; i++) {
    cout<< ptr[i] << ", ";
}
cout << "}"<<endl;

delete [] ptr;
return 0;
    
}
