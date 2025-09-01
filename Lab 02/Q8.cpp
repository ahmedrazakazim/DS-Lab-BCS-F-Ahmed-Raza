#include <iostream>

using namespace std;

void free2DArray(double** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    int numDays;
    int readingsPerDay;

    cout << "Enter the number of days: ";
    cin >> numDays;

    cout << "Enter the number of readings per day: ";
    cin >> readingsPerDay;

    double** temperatures = new double*[numDays];

    for (int i = 0; i < numDays; ++i) {
        temperatures[i] = new double[readingsPerDay];
        cout << "\nEnter temperatures for Day " << i + 1 << ":" << endl;
        for (int j = 0; j < readingsPerDay; ++j) {
            cout << "  Reading " << j + 1 << ": ";
            cin >> temperatures[i][j];
        }
    }

    double* dailyAverages = new double[numDays];
    int hottestDay = 0;
    int coldestDay = 0;

    cout << "\n--- Daily Average Temperatures ---" << endl;
    for (int i = 0; i < numDays; ++i) {
        double total = 0;
        for (int j = 0; j < readingsPerDay; ++j) {
            total += temperatures[i][j];
        }
        dailyAverages[i] = total / readingsPerDay;
        cout << "Day " << i + 1 << ": " << dailyAverages[i] << " degrees" << endl;

        if (dailyAverages[i] > dailyAverages[hottestDay]) {
            hottestDay = i;
        }
        if (dailyAverages[i] < dailyAverages[coldestDay]) {
            coldestDay = i;
        }
    }

    cout << "\n--- Temperature Extremes ---" << endl;
    cout << "The hottest day was Day " << hottestDay + 1 << " with an average of " << dailyAverages[hottestDay] << " degrees." << endl;
    cout << "The coldest day was Day " << coldestDay + 1 << " with an average of " << dailyAverages[coldestDay] << " degrees." << endl;

    free2DArray(temperatures, numDays);
    delete[] dailyAverages;

    return 0;
}
