lass Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // create queue data structure and push the first node into the queue 
        // it's is 0 base indexing graphs so push 0 into the queue 
        queue<int> q;
        q.push(0);
        
        // create visted array and mark visted first node 
        vector<int> vis(V,0);
        vis[0] = 1;
        
        vector<int> resultArray;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            resultArray.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return resultArray;
    }
};
