/* --------------------------- Approach - step by step ---------------------------

- create the adj list
- create queue data structre to perfrom disjtra algortim (bfs algorithm)
- need a distance array to storing the distance between nodes
- apply mathmathically equations 
   dis[node] + 1 = dis[it]
   current node wieight + unit wieght = dis[adjnodes wieight]
   dis[it] = dis[node] + 1;
   
   ex - 
   00 = 5 + 1
   5 + 1 = 00
   shorest path we want
   why we are taking 1 because accroding to questions we have unit wieght 
   
   NOTE:-
   Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
   Expected Space Complexity: O(N)
*/


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    
        // case 1 : create the adj list 
       vector<int> adj[N];
    
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
       
       // case 2 : need a queue data structure and dis array
       vector<int> dis(N);
       
       for(int i = 0; i<N; i++){
           dis[i] = INT_MAX;
       }
       
       queue<int> q;
       q.push(src);
       // push the node starting into the quque data structrue
       dis[src] = 0; // itself contain zero weight
       
       // case 3 : perfom disjtra algoritm (BFS)
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           for(auto it : adj[node]){
               if(dis[node] + 1 < dis[it]){
                   dis[it] = dis[node] + 1;
                // push into the queue, adj nodes all 
                   q.push(it);
               }
           }
       }
      // copy the all distance into the array 
      // but does't include infinte disination 
      vector<int> ans(N,-1);
      for(int i = 0; i<N; i++){
          if(dis[i]!= INT_MAX){
              ans[i] = dis[i];
          }
      }
      // return the ansewr 
      return ans;
    }
};