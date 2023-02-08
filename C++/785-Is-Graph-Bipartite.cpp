

// if anyone adjecency node have same color that i have - no bi-partite graphs
// otherwise tu hai

class Solution {
public:
     bool dfs(int node,vector<vector<int>>& graph, vector<int>& color){
        for(auto x:graph[node]){
            if(color[x]==-1){ // not coloured yet
                color[x]=1-color[node]; //reverse the color
                if(dfs(x,graph,color)==false)
                    return false;
            }
            else if(color[x]==color[node]) // already coloured and same colour
                return false;
        }
        // if both condtion is not false then offcouse  - TU EK BIPARTITE GRAPHS HAAY
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> color(size,-1);
        
        for(int i = 0; i<size; i++){
            if(color[i] == -1){
                color[i] = 1;
                if(dfs(i,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
