
/*
 Algorithm : TOPO SORT 
1. graphs base sorting algoritm
2. in this algoritm, there are u and v nodes, so u comes before v
		( exmaple me and my friend enter the class, so first me enter then my friend enter the class )
3. it is based no DAAG 
4. it is combination DEPTH FIRST SEARCH ( DFS  ) and stack 
 
 remember - people who are complete dfs call, just store into the stack 

*/

class Solution{
    public:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
	    vis[node] = 1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	    // insert into the stack,when dfs call complete 
	}
	
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>vis(V,0);
	    stack<int>st;
	    
	    for(int i =0; i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    
	    // move to stack to array element 
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
}
};
