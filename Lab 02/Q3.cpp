#include <iostream>
// Design a program to handle marks of students in different courses using a jagged array
// since each student is enrolled in a different number of courses)
// Input the number of courses each student takes.
// Dynamically allocate memory for each student accordingly.
// Calculate and display each student’s average marks 

using namespace std;

class Student {
public:
    string name;
    int* marks;
    int courses;

    Student(string n, int c) {
        name = n;
        courses = c;
        marks = new int[c];
    }

    ~Student() {
        delete[] marks;
    }

    void inputMarks() {
        cout << "Enter marks for " << name << ":" << endl;
        for (int i = 0; i < courses; i++) {
            cout << "Course " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    double calculateAverage() {
        int sum = 0;
        for (int i = 0; i < courses; i++) {
            sum += marks[i];
        }
        return (courses == 0) ? 0 : (double)sum / courses;  // C-style cast to double
    }
};

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    Student** students = new Student*[numStudents];

    for (int i = 0; i < numStudents; i++) {
        string name;
        int courses;

        cout << "Enter name of student #" << (i + 1) << ": ";
        cin >> name;
        cout << "Enter number of courses for " << name << ": ";
        cin >> courses;

        students[i] = new Student(name, courses);
        students[i]->inputMarks();
    }

    cout << "\nStudent Averages:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << students[i]->name << ": " << students[i]->calculateAverage() << endl;
    }

    for (int i = 0; i < numStudents; i++) {
        delete students[i];
    }
    delete[] students;

    return 0;
}
