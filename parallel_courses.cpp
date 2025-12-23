class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);

        // Build prerequisite bitmask
        for (auto &r : relations) {
            int u = r[0] - 1, v = r[1] - 1;
            prereq[v] |= (1 << u);
        }

        int FULL = (1 << n) - 1;
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask <= FULL; mask++) {
            if (dp[mask] == INT_MAX) continue;

            int available = 0;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) && (prereq[i] & mask) == prereq[i]) {
                    available |= (1 << i);
                }
            }

            // Enumerate subsets of available courses
            for (int sub = available; sub; sub = (sub - 1) & available) {
                if (__builtin_popcount(sub) <= k) {
                    dp[mask | sub] = min(dp[mask | sub], dp[mask] + 1);
                }
            }
        }

        return dp[FULL];
    }
};
