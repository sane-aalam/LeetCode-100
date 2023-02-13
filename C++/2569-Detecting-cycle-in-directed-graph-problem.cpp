class solution{
 public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // create inDgree Array/Vector for storing the inDgree 
	    vector<int> inDegree(V);
	    
	    // store the all inDgree into the array
	    for(int i = 0; i<V; i++){
	        for(auto it : adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    // create queue data sturucture
	    queue<int>q;
	    // check out the which nodes have indegree 0 (zero)
	    for(int i = 0; i<V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    // create the vector for storing the topo result
	    vector<int>topoArray;
	    
	    // check out the neigbours - who are the adjency nodes
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        // push into the topological sort array - storing the result;
	        topoArray.push_back(node);
	        
	        for(auto it: adj[node]){
	            // reduring the indegree part and check out the indegree which adjency node have 0 
	            // push into the queue data structure
	            inDegree[it] --;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    // 1 - way to checkout contain cycle 
	    // if you are able to perfrom complete TopoSort Algorithm then graph - no cycle
	    // if you are not able to perfrom complete TopoSrot(because this algo used only DAAG)
	    // so we say- topoArray is complete not fill using noes
	    // it would be stopped any node that have any cycle so we can say - cycle yes
	    if(topoArray.size() == V){
	        return false;
	    }else{
	        return true;
	    }
    }
};
