class Solution {
public:
    vector<int> ans;
    vector<vector<int>> graph;

    int dfs(int u, vector<int>& quiet) {
        
        if (ans[u] != -1) return ans[u];

        ans[u] = u; 
        for (int richerPerson : graph[u]) {
            int candidate = dfs(richerPerson, quiet);
            if (quiet[candidate] < quiet[ans[u]]) {
                ans[u] = candidate;
            }
        }

        return ans[u];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        graph.resize(n);
        ans.assign(n, -1);

        for (auto& r : richer) {
            graph[r[1]].push_back(r[0]);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, quiet);
        }

        return ans;
    }
};
