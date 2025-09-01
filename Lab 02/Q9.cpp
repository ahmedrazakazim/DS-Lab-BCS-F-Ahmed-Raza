#include <iostream>

using namespace std;

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];
    int nonZeroCount = 0;

    cout << "\nEnter matrix elements (0 for empty space):" << endl;
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    cout << "\n--- Normal Matrix ---" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int** compressedMatrix = new int*[nonZeroCount];
    int k = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                compressedMatrix[k] = new int[3];
                compressedMatrix[k][0] = i;
                compressedMatrix[k][1] = j;
                compressedMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    cout << "\n--- Compressed Form (Row, Col, Value) ---" << endl;
    for (int i = 0; i < nonZeroCount; ++i) {
        cout << compressedMatrix[i][0] << "\t" << compressedMatrix[i][1] << "\t" << compressedMatrix[i][2] << endl;
    }

    freeMatrix(matrix, rows);
    freeMatrix(compressedMatrix, nonZeroCount);

    return 0;
}
