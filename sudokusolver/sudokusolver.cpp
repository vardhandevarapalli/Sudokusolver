#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const int N = 9;

/* give input in the below format
0 0 0 0 9 4 0 3 0
0 0 0 5 1 0 0 0 7
0 8 9 0 0 0 0 4 0
0 0 0 0 0 0 9 0 0
5 0 0 0 0 0 0 0 8
0 0 4 0 0 0 0 0 0
0 7 0 0 0 0 2 6 0
9 0 0 0 8 3 0 0 0
0 5 0 1 7 0 0 0 0

*/

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isValid(int grid[N][N], int row, int col, int num) {
    // Check if num already exists in the current row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check if num already exists in the current column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check if num already exists in the current 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true; // The placement is valid
}

bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        printGrid(grid);
                        cout << endl;
                        this_thread::sleep_for(chrono::milliseconds(1)); // Pause for visualization
                        if (solveSudoku(grid)) {
                            return true;
                        }
                        grid[row][col] = 0;
                        printGrid(grid);
                        cout << endl;
                        this_thread::sleep_for(chrono::milliseconds(1)); // Pause for visualization
                    }
                }
                return false; // No valid number found, backtrack
            }
        }
    }
    return true; // Puzzle solved
}

int main() {
    int grid[N][N];

    cout << "Enter the Sudoku puzzle (row by row, use 0 for empty cells)in the given format: \n";
    cout << "0 0 0 0 9 4 0 3 0 \n";
    cout << "0 0 0 5 1 0 0 0 7 \n";
    cout << "0 8 9 0 0 0 0 4 0 \n";
    cout << "0 0 0 0 0 0 9 0 0 \n";
    cout << "5 0 0 0 0 0 0 0 8 \n";
    cout << "0 0 4 0 0 0 0 0 0 \n";
    cout << "0 7 0 0 0 0 2 6 0 \n";
    cout << "9 0 0 0 8 3 0 0 0 \n";
    cout << "0 5 0 1 7 0 0 0 0 \n";

    cout << "Now enter the code belwo \n \n";

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }

    cout << "Solving Sudoku puzzle...\n";

    if (solveSudoku(grid)) {
        cout << "Sudoku solved successfully:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}


