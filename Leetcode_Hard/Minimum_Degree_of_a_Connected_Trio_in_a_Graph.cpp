class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // Adjacency matrix for O(1) edge checks
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        
        // Degree of each node
        vector<int> degree(n + 1, 0);
        
        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (!adj[u][v]) {
                adj[u][v] = adj[v][u] = true;
                degree[u]++;
                degree[v]++;
            }
        }

        int ans = INT_MAX;

        // Find all connected trios
        for (int u = 1; u <= n; u++) {
            for (int v = u + 1; v <= n; v++) {
                if (!adj[u][v]) continue; // must be connected
                
                for (int w = v + 1; w <= n; w++) {
                    if (adj[u][w] && adj[v][w]) {
                        // Trio found
                        int trioDegree = degree[u] + degree[v] + degree[w] - 6;
                        ans = min(ans, trioDegree);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
