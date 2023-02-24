vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       vector<int>dist(V, INT_MAX);
       queue<int>q;
       q.push(S);
       dist[S] = 0;
       while(!q.empty()){
           int node = q.front();
           q.pop();
           for(auto i : adj[node]){
               int it = i[0];
               int dis = i[1];
               if(dist[it] > dist[node] + dis){
                   dist[it] = dist[node] + dis;
                   q.push(it);
               }
           }
       }
       return dist;
   }
};
