class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
                if (n == 1) return {0}; // Only one node

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

    //  Step 3: Populate the adjacency list and degree array

            for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        //For each edge [u, v], add v to u’s list and vice versa (since the graph is undirected).
        //Increase the degree (number of connections) of both nodes.


      //  🔹 Step 4: Find all leaf nodes (nodes with degree 1)

              queue<int> q;

        for (int i = 0; i < n; ++i) {   //These are the outermost nodes of the tree — leaves.
            if (degree[i] == 1) {       //We’ll remove these one level at a time (like BFS from outside-in).
                q.push(i);
            }
        }

        //🔹 Step 5: Start pruning leaves layer-by-layer
                int remaining = n;      //remaining keeps track of how many nodes are left.

        while (remaining > 2) {     //We stop when ≤ 2 nodes remain, because a tree can have at most 2 centroids.
            int sz = q.size();
            remaining -= sz;


                        for (int i = 0; i < sz; ++i) {
                int node = q.front(); q.pop();

        //For each leaf node in this layer...
                        for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }

        }

            //Decrease the degree of each of its neighbors (removing the leaf).
            //If any neighbor becomes a new leaf (degree == 1), add it to the queue.
            //This continues level by level, removing outer layers.


            //🔹 Step 6: Collect the last 1 or 2 remaining nodes
                    vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;

        
    }
};

