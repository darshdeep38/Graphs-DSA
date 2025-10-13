class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int , int >>q;
        int fresh = 0 ;

        // add all rottem oranges the queue and count fresh ones 
        for(int i = 0 ; i<rows; i++){

            for(int j = 0 ; j<cols;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] ==1){
                    fresh++;
                }
            }
        }


        // if no fresh oranges return zero
        if(fresh == 0) return 0;

          // Directions: up, down, left, right
          vector<pair<int , int >> directions = { {-1,0} , {0 ,-1} , {0,1} , {1,0}};
          int minutes = -1;


          //bfs
          while(!q.empty()){
            int size = q.size();
            minutes++;

        for(int i = 0 ; i< size; i++){
            auto[r,c] = q.front();
            q.pop();

            for(auto [dr , dc] : directions){
            int nr = r + dr , nc = c + dc;
            if(nr>=0 && nr <rows && nc >= 0 && nc < cols && grid[nr][nc] ==1){
                grid[nr][nc] = 2;
                fresh--;
                q.push({nr ,nc});
            }

            }
        }
          }

        return (fresh == 0) ? minutes : -1;

            }
};
