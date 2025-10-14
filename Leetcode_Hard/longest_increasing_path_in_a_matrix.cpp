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
