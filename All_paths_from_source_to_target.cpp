#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph, 0, path, result);
        return result;
    }

private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);
        
        // If we reached the target node (n-1), store the current path
        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            for (int next : graph[node]) {
                dfs(graph, next, path, result);
            }
        }
        
        // Backtrack
        path.pop_back();
    }
};
