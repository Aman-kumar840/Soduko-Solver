#include <iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in a cell
bool isSafe(int grid[N][N], int row, int col, int num)
{
    // Check if the number already exists in the same row or column
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }

    // Check if the number already exists in the same 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku grid
bool solveSudoku(int grid[N][N])
{
    int row, col;

    // Find an unassigned cell
    bool isUnassigned = false;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                isUnassigned = true;
                break;
            }
        }
        if (isUnassigned)
        {
            break;
        }
    }

    // If all cells are assigned, the Sudoku is solved
    if (!isUnassigned)
    {
        return true;
    }

    // Try different numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            // Assign the number if it's safe
            grid[row][col] = num;

            // Recursively solve the remaining grid
            if (solveSudoku(grid))
            {
                return true;
            }

            // Backtrack if the assigned number leads to an incorrect solution
            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int grid[N][N];

    // Read the Sudoku grid from input (0 represents empty cells)
    cout << "Enter the Sudoku grid (9x9):\n";
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cin >> grid[row][col];
        }
    }

    // Solve the Sudoku grid
    if (solveSudoku(grid))
    {
        cout << "Solution:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}
