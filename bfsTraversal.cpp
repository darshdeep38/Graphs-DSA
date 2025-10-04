// function for bfs traversal

void bfsTraversal( int src){
  queue<int> q;
  unordered_map<int , bool> visited;
  // initial state maintenance
  q.push(src);
  visited[src] = true;
   while(!q.empty()){
    int frontNode =  q.front();
    q.pop(); 

    // now we will go to all the neighbous of the front node
    for( auto neighbour : adjList[frontNode]){
      //neighbour --> pair
      //first valure -> node 
      // second value -> weight
      int node = neighbour.first;
      int weight = neighbour.second;
      if(!visited[node]){
        q.push(node);
        visited[node] = true;
      }
    }
   }
   cout<<endl;

}
