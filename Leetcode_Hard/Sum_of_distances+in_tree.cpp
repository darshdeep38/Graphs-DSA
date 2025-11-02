class Solution {
public:
    vector<int> ans, count;
    vector<vector<int>> graph;
    int n;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        graph.resize(n);
        ans.resize(n, 0);
        count.resize(n, 1); // each node counts as 1 itself

        // build adjacency list
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // 1st DFS: calculate count[] and ans[0] (sum of distances from root)
        dfs1(0, -1);

        // 2nd DFS: use parent info to compute answers for all nodes
        dfs2(0, -1);

        return ans;
    }

    // Post-order DFS to compute subtree sizes and total distance from root
    void dfs1(int node, int parent) {
        for (int nei : graph[node]) {
            if (nei == parent) continue;
            dfs1(nei, node);
            count[node] += count[nei];
            ans[0] += count[nei];
        }
    }

    // Pre-order DFS to compute distance sums for all nodes using parent results
    void dfs2(int node, int parent) {
        for (int nei : graph[node]) {
            if (nei == parent) continue;
            ans[nei] = ans[node] - count[nei] + (n - count[nei]);
            dfs2(nei, node);
        }
    }
};
