class Solution {
public:
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<vector<int>> ans;
    int timer;

    void dfs(int node, int parent) {
        tin[node] = low[node] = timer++;

        for (int neigh : adj[node]) {
            if (neigh == parent) continue;

            if (tin[neigh] == -1) {
                dfs(neigh, node);
                low[node] = min(low[node], low[neigh]);

                // bridge condition
                if (low[neigh] > tin[node]) {
                    ans.push_back({node, neigh});
                }
            } else {
                // back edge
                low[node] = min(low[node], tin[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        adj.resize(n);
        tin.assign(n, -1);
        low.assign(n, -1);
        timer = 0;

        // build graph
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // graph is connected, so start from node 0
        dfs(0, -1);

        return ans;
    }
};
