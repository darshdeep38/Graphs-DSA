class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string curr, string target, unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end()) return -1.0;
        if (curr == target) return 1.0;

        visited.insert(curr);
        for (auto& neighbor : graph[curr]) {
            string next = neighbor.first;
            double val = neighbor.second;
            if (visited.find(next) == visited.end()) {
                double result = dfs(next, target, visited);
                if (result != -1.0) return result * val;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        // Build graph
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        
        vector<double> results;
        for (auto& query : queries) {
            string C = query[0];
            string D = query[1];

            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(C, D, visited));
            }
        }
        return results;
    }
};
