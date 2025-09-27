class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n  = grid[0].size();
        vector<vector<bool>> visited(m , vector<bool>(n ,false));
        vector<pair<int , int>> directions = { {0,1} , {1,0} , {0,-1} , {-1,0}};


    for(int i = 0 ; i<m;i++){
        for(int j = 0 ; j<n ; j++){
            if(!visited[i][j]){    // if a node is unvisited we start a bfs setup for it 

            queue<tuple<int , int , int , int >>q;    // current x , current y , parent x , parent y
            q.push({i , j , -1 , -1 });
            visited[i][j] = true ;       
            while(!q.empty()){
                auto [x , y ,px , py] = q.front();   // Extract the current cell's coordinates and its parent.
                q.pop();

            //  Check All Neighbors
            for(auto [dx , dy] : directions){
                int nx = x + dx ;
                int ny = y + dy;


                if(nx < 0 || ny < 0 || nx >= m || ny>= n){
                    continue;
                }

                // Ignore out-of-bound cells
                if(grid[nx][ny] != grid[x][y])  continue;   //Only continue if neighbor has same character.
 
                if(!visited[nx][ny]){
                    visited[nx][ny] =  true;  //If the neighbor is not visited, mark it and add to the queue, 
                    q.push({nx , ny , x , y});   // remembring that we came from (x, y)
                }

                //cycle detection
                else if(nx != px  || ny != py){
                    return true;
                }

            }


            }



            }
        }
    }
    return false;
    }
};
