// 210. Course Schedule II - using kahn's algoritm 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // 1 - create adjecncy list
        int V = numCourses;
        vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}

        // 2 - create indegree of the node
		vector<int> indegree(V , 0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

        // 3 - create queue data structure and push the which have indegree zero
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

        //4 - pop the node and checkout the neighbous node reduce the indegree of the node 
        // if any node have indgree zero then push into the queue 
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
        // if you are able to finish all courses - return storing the answer;
        // otherwise return empty answer
		if (topo.size() == V) return topo;
		return {};
    }
};