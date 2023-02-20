
class Solution {

// Topo sort based questions ):
// Approach

// In this question we have to find nodes with outdegree=0
// so we will reverse the direction of edges 
// and we will apply topological sort and 
// find Queue having indegree=0

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> indegree(V,0);
        vector<int> reverseAdj[V];

        for(int i=0; i<V; i++){
            for(auto it : graph[i]){
                // i -> it 
                // not we are using it -> i
                reverseAdj[it].push_back(i);
                indegree[i] ++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> safe;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(auto it : reverseAdj[node]){
                indegree[it] --;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};
