class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0)); // memoization table
        int maxPath = 0;

        // 4 directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        // DFS function with memoization
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != 0) return dp[i][j]; // return memoized result

            int maxLength = 1;

            for (auto [dx, dy] : directions) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] > matrix[i][j]) {
                    maxLength = max(maxLength, 1 + dfs(x, y));
                }
            }

            return dp[i][j] = maxLength; // memoize result
        };

        // run DFS from every cell
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxPath = max(maxPath, dfs(i, j));
            }
        }

        return maxPath;
    }
};

/*
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
We define a public class Solution with the function longestIncreasingPath().

It takes a reference to a 2D vector matrix as input and returns an integer (the longest increasing path length).


        if (matrix.empty() || matrix[0].empty()) return 0;
Safety check: If the matrix is empty or has empty rows, return 0 immediately.


        int rows = matrix.size(), cols = matrix[0].size();
Get the number of rows and columns in the matrix.


        vector<vector<int>> dp(rows, vector<int>(cols, 0)); // memoization table
dp[i][j] will store the length of the longest increasing path starting from cell (i, j).

Initially set to 0 (meaning uncomputed).


        int maxPath = 0;
This variable will store the maximum path length found across all cells.


        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
These represent the 4 directions: up, down, left, right.

Used to explore adjacent cells.

 DFS with Memoization (Top-down DP)

        function<int(int, int)> dfs = [&](int i, int j) -> int {
We define a lambda function (an inline DFS function) using std::function.

dfs(i, j) returns the longest increasing path starting at cell (i, j).


            if (dp[i][j] != 0) return dp[i][j]; // return memoized result
If we’ve already computed the result for (i, j), return it to avoid redundant work.


            int maxLength = 1;
Start with length 1 — every cell is a path of length 1 by itself.


            for (auto [dx, dy] : directions) {
                int x = i + dx, y = j + dy;
Loop over each direction and compute the neighbor cell coordinates (x, y).


                if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] > matrix[i][j]) {
Check if:

The new cell is within bounds.

The value is greater than the current cell (increasing path condition).


                    maxLength = max(maxLength, 1 + dfs(x, y));
If valid, recursively call dfs(x, y) and update maxLength.

We add 1 to include the current cell in the path.


            }
            return dp[i][j] = maxLength; // memoize result
        };
After exploring all valid directions, we store and return the result for (i, j) in dp.

 Run DFS from Every Cell

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxPath = max(maxPath, dfs(i, j));
            }
        }
We run DFS from every cell, as the longest path could start anywhere.

We update maxPath with the maximum length found.


        return maxPath;
    }
};
Finally, return the longest increasing path length.

*/
