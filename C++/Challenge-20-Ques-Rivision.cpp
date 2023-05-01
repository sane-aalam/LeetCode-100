// Today all questions - i have sovled 

// question 1 breath first search
 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        // create the visted array 
        vector<int> vis(V,0);
        // create queue data structure
        queue<int> q;
        // mark visted and push into the queue data structre
        q.push(0);
        vis[0] = 1;
        vector<int> container;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            container.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return container;
}

// questions - 2 :   Depth first search 

 void dfs(int node,vector<int> & vis,vector<int> &container,vector<int> adj[]){
       // mark visted into & push into the array
       vis[node] = 1;
       
       container.push_back(node);
       
       for(auto it: adj[node]){
           if(!vis[it]){
               dfs(it,vis,container,adj);
           }
       }
   }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> container;
        vector<int> vis(V,0);
        dfs(0,vis,container,adj);
        return container;
    }
};
