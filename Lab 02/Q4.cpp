#include <iostream>
#include <iomanip>

using namespace std;

void resizeArray(double*& arr, int& size, int newSize) {
    if (newSize <= size) {
        cout << "New size must be greater than current size." << endl;
        return;
    }
    double* newArr = new double[newSize];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
}

int main() {
    int numMonths;
    cout << "Enter the number of months to track: ";
    cin >> numMonths;

    double* expenses = new double[numMonths];

    for (int i = 0; i < numMonths; ++i) {
        cout << "Enter expenses for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    int choice;
    cout << "\nDo you want to add more months? (1 for Yes, 0 for No): ";
    cin >> choice;

    if (choice == 1) {
        int additionalMonths;
        cout << "Enter the number of additional months: ";
        cin >> additionalMonths;
        int newSize = numMonths + additionalMonths;
        resizeArray(expenses, numMonths, newSize);

        for (int i = numMonths - additionalMonths; i < numMonths; ++i) {
            cout << "Enter expenses for new month " << i + 1 << ": ";
            cin >> expenses[i];
        }
    }

    double total = 0;
    for (int i = 0; i < numMonths; ++i) {
        total += expenses[i];
    }

    double average = total / numMonths;

    cout << "\n--- Expense Summary ---" << endl;
    cout << "Total expenses: $" << fixed << setprecision(2) << total << endl;
    cout << "Average monthly expense: $" << fixed << setprecision(2) << average << endl;

    delete[] expenses;

    return 0;
}
