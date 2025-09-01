#include <iostream>

using namespace std;

void freeJaggedArray(double** array, int* employees, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    delete[] employees;
}

int main() {
    int numDepartments;

    cout << "Enter the number of departments: ";
    cin >> numDepartments;

    double** salaries = new double*[numDepartments];
    int* employeesInDepartment = new int[numDepartments];

    cout << "\nEnter employee salaries for each department:" << endl;
    for (int i = 0; i < numDepartments; ++i) {
        cout << "\nDepartment " << i + 1 << endl;
        cout << "Enter the number of employees: ";
        cin >> employeesInDepartment[i];
        salaries[i] = new double[employeesInDepartment[i]];
        for (int j = 0; j < employeesInDepartment[i]; ++j) {
            cout << "Enter salary for employee " << j + 1 << ": ";
            cin >> salaries[i][j];
        }
    }

    double* highestSalaries = new double[numDepartments];
    double* averageSalaries = new double[numDepartments];

    for (int i = 0; i < numDepartments; ++i) {
        if (employeesInDepartment[i] > 0) {
            double maxSalary = salaries[i][0];
            double totalSalary = 0;
            for (int j = 0; j < employeesInDepartment[i]; ++j) {
                if (salaries[i][j] > maxSalary) {
                    maxSalary = salaries[i][j];
                }
                totalSalary += salaries[i][j];
            }
            highestSalaries[i] = maxSalary;
            averageSalaries[i] = totalSalary / employeesInDepartment[i];
        } else {
            highestSalaries[i] = 0;
            averageSalaries[i] = 0;
        }
    }

    cout << "\n--- Salary Analysis ---" << endl;
    for (int i = 0; i < numDepartments; ++i) {
        cout << "Department " << i + 1 << ": Highest Salary = $" << highestSalaries[i] << ", Average Salary = $" << averageSalaries[i] << endl;
    }

    int departmentWithMaxAvg = 0;
    double maxAvgSalary = 0;
    for (int i = 0; i < numDepartments; ++i) {
        if (averageSalaries[i] > maxAvgSalary) {
            maxAvgSalary = averageSalaries[i];
            departmentWithMaxAvg = i + 1;
        }
    }

    cout << "\nDepartment " << departmentWithMaxAvg << " has the highest average salary of $" << maxAvgSalary << "." << endl;

    freeJaggedArray(salaries, employeesInDepartment, numDepartments);
    delete[] highestSalaries;
    delete[] averageSalaries;

    return 0;
}
