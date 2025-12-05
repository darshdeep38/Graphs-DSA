class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0/1 = two colors
        
        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue;  // Already colored in earlier BFS
            
            queue<int> q;
            q.push(start);
            color[start] = 0;  // Start with color 0
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        // Color the neighbor with opposite color
                        color[v] = 1 - color[u];
                        q.push(v);
                    } 
                    else if (color[v] == color[u]) {
                        // Adjacent same color → not bipartite
                        return false;
                    }
                }
            }
        }
        
        return true; // No conflict found
    }
};

