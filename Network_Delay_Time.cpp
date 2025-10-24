#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

class Solution {
public:
    /**
     * Finds the minimum time required for a signal to reach all N nodes from source K.
     * Uses Dijkstra's algorithm to find the shortest path to every node.
     * * @param times A list of travel times (u, v, w) where w is the time from u to v.
     * @param n The number of nodes (labeled from 1 to n).
     * @param k The source node.
     * @return The minimum time for all nodes to receive the signal, or -1 if impossible.
     */
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        // 1. Build the Adjacency List
        // adj[u] = list of {v, w} pairs, representing an edge from u to v with time w.
        std::vector<std::pair<int, int>> adj[n + 1];
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // 2. Initialize Distances and Priority Queue
        // dist[i] will store the shortest time from K to node i.
        // We use a large number (like 10^9) for infinity.
        const int INF = 1e9;
        std::vector<int> dist(n + 1, INF);

        // Priority Queue: Stores pairs of {time, node}. It's a min-heap 
        // prioritized by time (first element) to always process the closest node first.
        // std::greater<T> makes it a min-heap.
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> pq;

        // Set the distance for the source node K to 0 and push it to the queue.
        dist[k] = 0;
        pq.push({0, k}); // {time, node}

        // 3. Dijkstra's Algorithm
        while (!pq.empty()) {
            int time = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization: If the extracted time is already greater than the known shortest 
            // path to u, it's an outdated entry, so we skip it.
            if (time > dist[u]) {
                continue;
            }

            // Iterate through all neighbors (v) of the current node (u).
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int travel_time = edge.second;

                // Check for a relaxation: If the new path (dist[u] + travel_time) 
                // is shorter than the currently known shortest path to v (dist[v]).
                if (dist[u] + travel_time < dist[v]) {
                    // Update the shortest path to v.
                    dist[v] = dist[u] + travel_time;
                    
                    // Push the new, shorter path to the priority queue.
                    pq.push({dist[v], v});
                }
            }
        }

        // 4. Determine the Result
        // The result is the maximum of all shortest path times.
        int max_time = 0;
        // Nodes are 1-indexed, so we iterate from 1 to n.
        for (int i = 1; i <= n; ++i) {
            // If any node is unreachable (distance is still INF), return -1.
            if (dist[i] == INF) {
                return -1;
            }
            // Otherwise, track the maximum shortest time.
            max_time = std::max(max_time, dist[i]);
        }

        // max_time is the time when the last node receives the signal.
        return max_time;
    }
};

