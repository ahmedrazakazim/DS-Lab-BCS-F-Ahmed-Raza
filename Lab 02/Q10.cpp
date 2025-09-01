#include <iostream>

using namespace std;

void freeLibrary(int** library, int* bookCounts, int numCategories) {
    for (int i = 0; i < numCategories; ++i) {
        delete[] library[i];
    }
    delete[] library;
    delete[] bookCounts;
}

int main() {
    int numCategories;

    cout << "Enter the number of library categories: ";
    cin >> numCategories;

    int** library = new int*[numCategories];
    int* bookCounts = new int[numCategories];

    cout << "\nEnter book IDs for each category:" << endl;
    for (int i = 0; i < numCategories; ++i) {
        cout << "\nCategory " << i + 1 << " (e.g., Fiction, Science)" << endl;
        cout << "Enter the number of books in this category: ";
        cin >> bookCounts[i];

        library[i] = new int[bookCounts[i]];
        for (int j = 0; j < bookCounts[i]; ++j) {
            cout << "Enter book ID " << j + 1 << ": ";
            cin >> library[i][j];
        }
    }

    int searchID;
    cout << "\nEnter a book ID to search for: ";
    cin >> searchID;

    bool found = false;
    int foundCategory = -1;

    for (int i = 0; i < numCategories; ++i) {
        for (int j = 0; j < bookCounts[i]; ++j) {
            if (library[i][j] == searchID) {
                found = true;
                foundCategory = i + 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    cout << "\n--- Search Result ---" << endl;
    if (found) {
        cout << "Book ID " << searchID << " is available." << endl;
        cout << "It is located in Category " << foundCategory << "." << endl;
    } else {
        cout << "Book ID " << searchID << " is not available in the library." << endl;
    }

    freeLibrary(library, bookCounts, numCategories);

    return 0;
}
