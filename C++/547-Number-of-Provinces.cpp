//547. Number of Provinces

class Solution {
private:
   void dfs(vector<vector<int>>& M, vector<bool>& vis, int i){
    vis[i]=true;
    
	for(int j=0;j<M.size();j++){
        // [[1,1,0],[1,1,0],[0,0,1]]
        // if node is not visted and not value is 1 means you are my value, you are not 0;
        // isConnected[i][i] == 1
        if(M[i][j]==1 && !vis[j])
			dfs(M,vis,j);
    }
  }   
public:
int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        if(n==0) 
            return 0;
    
        vector<bool>vis(n,false);

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    count++;
                    dfs(isConnected,vis,i);
                }
            }

	  return count;    
    }
};
