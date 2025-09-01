#include <iostream>

using namespace std;

double** createMatrix(int rows, int cols) {
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void readMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

double** addMatrices(double** matrix1, double** matrix2, int rows, int cols) {
    double** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

double** subtractMatrices(double** matrix1, double** matrix2, int rows, int cols) {
    double** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows for the matrices: ";
    cin >> rows;
    cout << "Enter the number of columns for the matrices: ";
    cin >> cols;

    double** matrix1 = createMatrix(rows, cols);
    double** matrix2 = createMatrix(rows, cols);

    cout << "\n--- Enter elements for Matrix 1 ---" << endl;
    readMatrix(matrix1, rows, cols);

    cout << "\n--- Enter elements for Matrix 2 ---" << endl;
    readMatrix(matrix2, rows, cols);

    double** sumMatrix = addMatrices(matrix1, matrix2, rows, cols);
    double** diffMatrix = subtractMatrices(matrix1, matrix2, rows, cols);

    cout << "\n--- Matrix 1 ---" << endl;
    printMatrix(matrix1, rows, cols);

    cout << "\n--- Matrix 2 ---" << endl;
    printMatrix(matrix2, rows, cols);

    cout << "\n--- Sum of Matrices ---" << endl;
    printMatrix(sumMatrix, rows, cols);

    cout << "\n--- Difference of Matrices ---" << endl;
    printMatrix(diffMatrix, rows, cols);

    freeMatrix(matrix1, rows);
    freeMatrix(matrix2, rows);
    freeMatrix(sumMatrix, rows);
    freeMatrix(diffMatrix, rows);

    return 0;
}
