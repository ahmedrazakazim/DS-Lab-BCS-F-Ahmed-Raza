#include <iostream>
#include <string>

using namespace std;

#define TABLE_CAPACITY 15

class EnrollmentDirectory{
    string studentName[TABLE_CAPACITY];
    int studentID[TABLE_CAPACITY];
    bool isSlotUsed[TABLE_CAPACITY];

    public:
    EnrollmentDirectory(){
        for(int i = 0 ; i < TABLE_CAPACITY ; i++){
            isSlotUsed[i] = false;
        }
    }

    int calculateHomeIndex(int key){
        return key % TABLE_CAPACITY;
    }

    void placeRecord(int keyID , string studentN){
        int index = calculateHomeIndex(keyID);
        int startIndex = index;
        int probeStep = 1;

        while(isSlotUsed[index]){
            if(studentID[index] == keyID){
                studentName[index] = studentN;
                return;
            }
            index = (index + probeStep * probeStep) % TABLE_CAPACITY;
            
            if(index == startIndex){
                cout << "Hash table is full." << endl;
                return;
            }
            probeStep++;
        }

        studentID[index] = keyID;
        studentName[index] = studentN;
        isSlotUsed[index] = true;
    }

    void locateRecord(int numID){
        int index = calculateHomeIndex(numID);
        int probeStep = 1;
        int startIndex = index;

        while(isSlotUsed[index]){
            if(studentID[index] == numID){
                cout << "The student " << studentName[index] << " has roll number " << numID << endl;
                cout << endl;
                return;
            }
            index = (index + probeStep * probeStep ) % TABLE_CAPACITY;
            probeStep++;
            
            if(index == startIndex){
                break;
            }
        }
        cout << "Roll number not found." << endl;
        cout << endl;
    }

    void displayDirectory(){
        for(int i = 0 ; i < TABLE_CAPACITY ; i++){
            if(!isSlotUsed[i]){
                continue;
            }
            cout << "[" << i << "]" ;
            cout << "(" << studentID[i] << "," << studentName[i] << ")" << endl;
        }
        cout << endl;
    }
};


int main(){
    EnrollmentDirectory studentTable;
    studentTable.placeRecord(812 , "Laiba");
    studentTable.placeRecord(688 , "Simal");
    studentTable.placeRecord(852 , "Armeen");
    studentTable.placeRecord(654 , "Ariza");
    studentTable.placeRecord(827 , "Maryam");
    studentTable.displayDirectory();

    cout << "Searching..." << endl;
    studentTable.locateRecord(852);
    cout << "Searching..." << endl;
    studentTable.locateRecord(345);

    return 0;
}
