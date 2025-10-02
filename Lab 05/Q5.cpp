#include <iostream>
using namespace std;

#define N 9

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


bool isValid(int grid[N][N], int row, int col, int num) 
{

    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) return false;
  
    }
   
    for (int x = 0; x < N; x++)
      {
        if (grid[x][col] == num) return false;
    }

  
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) return false;
          }
    }
  
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row = -1, col = -1;
    bool isEmpty = false;


    for (int i = 0; i < N && !isEmpty; i++) {
        for (int j = 0; j < N && !isEmpty; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
            }
        }
    }


    if (!isEmpty) return true;


    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

    
            if (solveSudoku(grid)) return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (solveSudoku(grid)) 
    {
      
        cout<< "Solved Sudoku:\n";
        printGrid(grid);
    } 
    else
    {
        cout<< "No solution exists." << endl;
    }


  
    return 0;
}
