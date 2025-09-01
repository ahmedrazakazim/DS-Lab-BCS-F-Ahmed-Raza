#include <iostream>

using namespace std;

class SafeIntPointer {
private:
    int* _ptr;

public:
    SafeIntPointer(int* ptr) : _ptr(ptr) {}

    ~SafeIntPointer() {
        delete _ptr;
    }

    void setValue(int value) {
        if (_ptr) {
            *_ptr = value;
        }
    }

    int getValue() const {
        if (_ptr) {
            return *_ptr;
        }
        return 0;
    }

    int* release() {
        int* temp = _ptr;
        _ptr = nullptr;
        return temp;
    }
};

int main() {
    const int num_students = 5;
    SafeIntPointer* studentMarks[num_students];

    cout << "Demonstrating the SafeIntPointer class." << endl;

    for (int i = 0; i < num_students; ++i) {
        studentMarks[i] = new SafeIntPointer(new int);
        studentMarks[i]->setValue(85 + i * 2);
    }

    cout << "\nStudent marks stored using the safe pointer class:" << endl;
    for (int i = 0; i < num_students; ++i) {
        cout << "Student " << i + 1 << " mark: " << studentMarks[i]->getValue() << endl;
    }

    int* releasedPointer = studentMarks[2]->release();
    if (releasedPointer) {
        cout << "\nValue of the released pointer: " << *releasedPointer << endl;
        delete releasedPointer;
        studentMarks[2] = nullptr;
    }

    cout << "\nAfter releasing a pointer, the array remains safe." << endl;
    for (int i = 0; i < num_students; ++i) {
        if (studentMarks[i]) {
            cout << "Student " << i + 1 << " mark: " << studentMarks[i]->getValue() << endl;
        } else {
            cout << "Student " << i + 1 << " mark: Pointer was released." << endl;
        }
    }

    for (int i = 0; i < num_students; ++i) {
        delete studentMarks[i];
    }

    return 0;
}
