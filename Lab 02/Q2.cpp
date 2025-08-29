#include <iostream>

using namespace std;
int main() {
    
int rows,cols;
cout <<"Enter Rows: "<<endl;
cin >> rows;
cout <<"Enter Columns: "<<endl;
cin >> cols;

int **ptr = new int*[rows];
for (int i=0; i <rows;i++) {
    ptr[i] = new int [cols];
}

for (int i=0;i <rows;i++) {
    for (int j=0;j<cols;j++){
        ptr[i][j]=0;
    }
}

cout <<"Enter elements (0 for empty, 1 for occupied): "<< endl;
for (int i=0 ;i< rows ;i++) {
    for (int j=0 ;j < cols ;j++){
        cin >> ptr[i][j];
    }
}
cout <<endl;
//displaying matrix
cout<< "Final Matrix: "<<endl;
for (int i=0;i <rows;i++) {
    for (int j=0;j<cols;j++){
        cout<< ptr[i][j];
    }
    cout <<endl;
}

for (int i=0; i <rows;i++) {
    delete [] ptr[i];
}
delete []ptr;

return 0;

}
