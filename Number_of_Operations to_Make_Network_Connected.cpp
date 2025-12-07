class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() <  n -1 ) return -1 ; 

        vector<vector<int>> adj(n);
        for( auto &c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        
        vector<bool> visited(n , false);
        int components = 0 ;

        // BFS to count connected components
        for( int i = 0 ; i< n ; i++){
            if(!visited[i]){
                components++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                 int node = q.front();
                 q.pop();
                 for(int nei : adj[node]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                 }
                }
            }

        }
    return components -1 ;
    }
};
