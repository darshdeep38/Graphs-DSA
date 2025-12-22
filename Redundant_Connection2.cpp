class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);

        vector<int> edge1, edge2;

        // Step 1: Find node with two parents
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                edge1 = {parent[v], v};
                edge2 = {u, v};
                e[1] = 0;  // mark edge2 as invalid temporarily
            }
        }

        // Union-Find
        vector<int> dsu(n + 1);
        for (int i = 1; i <= n; i++)
            dsu[i] = i;

        function<int(int)> find = [&](int x) {
            if (dsu[x] != x)
                dsu[x] = find(dsu[x]);
            return dsu[x];
        };

        // Step 2: Detect cycle
        for (auto &e : edges) {
            if (e[1] == 0) continue;

            int u = e[0], v = e[1];
            int pu = find(u);
            if (pu == v) {
                // cycle found
                return edge1.empty() ? e : edge1;
            }
            dsu[v] = pu;
        }

        // Step 3: No cycle, return second edge
        return edge2;
    }
};
