#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].emplace_back(v, w);
        }

        // Step 2: Min heap (cost, node, stops)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});  // {cost, node, stops}

        // Track visited: minCost[node][stops] = cost
        vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
        minCost[src][0] = 0;

        while (!pq.empty()) {
            vector<int> top = pq.top(); pq.pop();
            int cost = top[0], u = top[1], stops = top[2];

            if (u == dst) return cost;

            if (stops > k) continue;

            for (auto& [v, price] : adj[u]) {
                int newCost = cost + price;

                if (newCost < minCost[v][stops + 1]) {
                    minCost[v][stops + 1] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
