

/*Topo sort - something comes before something then use Toposort and kahn's algorithm*/

// start code -
// good morning ! sane

// TC = 0(V+E) && Sc = 0(N) + 0(N)

class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 	{
	    
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
	    return topoArray;
	}
};
