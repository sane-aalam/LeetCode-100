// GEEKSFROGEEK = https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

/*
Approach simple-

1. we want to shorted path 
2. when we see shortest ( int matrix base problem ) keyword then 
 100% don't think too must- 
 directly use Dijstra algorithm

 Tc - ElogV 

*/


class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        // what if give source is contain zero 0 not 1
        // not possilbe to reach source to distination
        if(A[0][0] == 0) 
            return -1;

        // create queue data and push into starting row and starting col into the queue and 
        // intially paht = 0 
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}}); 

        // create the visted 2d array and mark visted 
        vector<vector<int>> vis(N,vector<int>(M,0));
        vis[0][0] = 1;
        
        // perfom BFS and dijstra algorithm
        
        while(!q.empty()){
            int path = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            // chekout the souce indexes reach to the distination 
            if(row == X && col == Y){
                return path;
            }
            
            // go the 4-direction
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int way = 0; way < 4; way++){
                int newrow = delrow[way] + row;
                int newcol = delcol[way] + col;
                
                if(newrow >= 0 && newrow < N && newcol >= 0 && newcol < M && 
                !vis[newrow][newcol] && A[newrow][newcol] == 1){
                    vis[newrow][newcol] = 1;
                    q.push({path+1,{newrow,newcol}});
                } 
            }
            
        }
        // not possible to reach source to distanation 
        return - 1;
    }
};
