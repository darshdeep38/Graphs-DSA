class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        // Step 1: Distance matrix initialization
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        // Load edges
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Step 2: Floyd–Warshall for All-Pairs Shortest Paths
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Step 3: Count reachable cities for each city
        int answer = -1;
        int minReachable = INT_MAX;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) count++;
            }

            // exclude itself
            count--;  

            // choose the city with:
            //  → minimum reachable count
            //  → if tie: maximum city index
            if(count <= minReachable) {
                minReachable = count;
                answer = i;
            }
        }

        return answer;
    }
};
