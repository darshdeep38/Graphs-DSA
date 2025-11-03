#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        // Each state: (node, mask)
        // mask indicates which nodes have been visited
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize queue with each node as a starting point
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            q.push({i, mask});
            visited[i][mask] = true;
        }

        int steps = 0;
        int targetMask = (1 << n) - 1;  // all nodes visited

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, mask] = q.front();
                q.pop();

                for (int nei : graph[node]) {
                    int nextMask = mask | (1 << nei);
                    if (nextMask == targetMask) {
                        return steps + 1;
                    }
                    if (!visited[nei][nextMask]) {
                        visited[nei][nextMask] = true;
                        q.push({nei, nextMask});
                    }
                }
            }
            steps++;
        }

        return -1; // should never reach here
    }
};
