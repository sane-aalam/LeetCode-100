// 323. Number of Connected Components in an Undirected Graph (Leetcode)

/*
---------------questions-----------------

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4
Output: 2

There are two base indexing graphs
one is 0 base.
second is 1 base.
but we are taking 0 base indexing ):

your task to Return the number of connected components in the graph.
*/


// Approach simple hay ---
// 1. we are taking visted array 
// 2. apply traversal algorithm
// 3. acccording the algorithm, it completed all nodes using adj list 
// 4. everycall BFS/DFS increse the counter 

class Solution {
    private:
    void BFS(int node, vector<int> vis, vector<int> adj[]){

        queue<int> q;
        int startingNode = 0;
        q.push(startingNode);
        vis[0] = 1;
        // mark visited this particular node - we can say starting node 

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // we are not storging the nodes that why are not taking here any extra array and vector
            //  for storing the nodes
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    public:
    int connectedComponents(int V, vector<int> adj[]) {
        // start your code ):
        vector<int> vis(V,0);
        int components = 0;

        for(int index = 0; index < V; index++){
            if(!vis[index]){
                BFS(index,vis,adj);
                components = components + 1;
            }
        }
        return components;
    }
};


/*
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
Auxiliary Space: O(V)
*/

// Thank you ):
// Sane )----