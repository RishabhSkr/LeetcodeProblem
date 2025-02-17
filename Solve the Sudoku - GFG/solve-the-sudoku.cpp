//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
      int row, col;
        // If there are no unassigned cells, Sudoku is solved.
        if (!FindUnassignedLocation(grid, row, col))
            return true;

        // Try numbers 1 to 9 for the unassigned cell.
        for (int num = 1; num <= 9; num++) {
            // If the number is safe to place at the current location.
            if (isSafe(grid, row, col, num)) {
                // Assign the number to the current cell.
                grid[row][col] = num;

                // Recursively solve the rest of the Sudoku.
                if (SolveSudoku(grid))
                    return true;

                // If the current assignment does not lead to a solution,
                // revert the assignment and try the next number.
                grid[row][col] = 0;
            }
        }

        // If no number can be placed in the current cell,
        // return false to backtrack.
        return false;
    }

    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << grid[i][j] << " ";
            }
        }
    }

private:
    // Function to find an unassigned location in the grid.
    bool FindUnassignedLocation(int grid[N][N], int& row, int& col) {
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == 0)
                    return true;
            }
        }
        return false;
    }

    // Function to check if it's safe to place a number in a cell.
    bool isSafe(int grid[N][N], int row, int col, int num) {
        // Check if the number is not present in the current row and column.
        for (int i = 0; i < N; i++) {
            if (grid[row][i] == num || grid[i][col] == num)
                return false;
        }

        // Check if the number is not present in the 3x3 sub-grid.
        int subGridRow = row - row % 3;
        int subGridCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + subGridRow][j + subGridCol] == num)
                    return false;
            }
        }

        return true;
    }

};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends