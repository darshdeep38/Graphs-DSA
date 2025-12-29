class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        // Adjacency lists for red and blue edges
        vector<vector<int>> redAdj(n), blueAdj(n);

        for (auto &e : redEdges)
            redAdj[e[0]].push_back(e[1]);

        for (auto &e : blueEdges)
            blueAdj[e[0]].push_back(e[1]);

        // dist[node][color]
        // color: 0 -> last edge was red, 1 -> last edge was blue
        vector<vector<int>> dist(n, vector<int>(2, -1));

        queue<pair<int, int>> q;

        // Start from node 0, both colors allowed initially
        dist[0][0] = dist[0][1] = 0;
        q.push({0, 0}); // last color red
        q.push({0, 1}); // last color blue

        while (!q.empty()) {
            auto [node, lastColor] = q.front();
            q.pop();

            // If last was red, next must be blue
            if (lastColor == 0) {
                for (int nei : blueAdj[node]) {
                    if (dist[nei][1] == -1) {
                        dist[nei][1] = dist[node][0] + 1;
                        q.push({nei, 1});
                    }
                }
            }
            // If last was blue, next must be red
            else {
                for (int nei : redAdj[node]) {
                    if (dist[nei][0] == -1) {
                        dist[nei][0] = dist[node][1] + 1;
                        q.push({nei, 0});
                    }
                }
            }
        }

        // Prepare final answer
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1) ans[i] = dist[i][1];
            else if (dist[i][1] == -1) ans[i] = dist[i][0];
            else ans[i] = min(dist[i][0], dist[i][1]);
        }

        return ans;
    }
};
