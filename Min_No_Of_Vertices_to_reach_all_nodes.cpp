class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n , false);

        // mark the nodes having incoming edges
        for( const auto & edge : edges){
            hasIncoming[edge[1]] = true;
        }

        vector<int> result ;
        // nodes without incoming edges must be included in the result 
        for(int i = 0 ; i< n; i++){
            if(!hasIncoming[i]){
                result.push_back(i);
            }
        }

        return result ;

    }
};
