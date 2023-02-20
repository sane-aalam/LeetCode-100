
Leetcode pri

class Solution{
    public:
    vector<int> topo(int V, vector<int> adj[]) {
        // create the ans array and storing the solutions 
        // create the indegree array - for storing the indegree of the node 
        vector<int> ans, in(V, 0);
        queue<int> q;
        for(int i=0;i<V;i++) {
            for(auto x: adj[i]) {
                in[x]++;
            }
        }
        for(int i=0;i<V;i++) if(in[i]==0) q.push(i);
        while(q.size()) {
            int node=q.front(); q.pop();
            ans.push_back(node);
            for(auto x: adj[node]) {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
        }
        return ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        string a, b, ans="";
        
        vector<int> adj[k];
        
        for(int i=0;i<n-1;i++) {
            a=dict[i], b=dict[i+1];
            
            int len = min(a.size(), b.size());
            
            for(int ptr=0;ptr<len; ptr++) {
                if(a[ptr] != b[ptr]) {
                    adj[a[ptr]-'a'].push_back(b[ptr]-'a');
                    break;
                }
            }
        }
        vector<int> topoArray=topo(k, adj);
        for(auto x: topoArray) {
            ans += (x+'a');
        }
        return ans;
    }
};
