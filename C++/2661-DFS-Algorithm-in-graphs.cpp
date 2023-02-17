class Solution {
   private:
    void dfs(int node,int vist[], vector<int> adj[],vector<int>&result){
        
        // mark visted and push into the result array
        vist[node] = 1;
        result.push_back(node);
        
        // traversal code - WRTN
        for(auto x : adj[node]){
            if(!vist[x]){
                dfs(x,vist,adj, result);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       int vist[V] = {0};
       vector<int> result;
       int start = 0; // starting node 0
       dfs(start,vist,adj,result);
       return result;
    }
};
