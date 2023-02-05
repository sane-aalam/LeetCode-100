
class Solution {
private:
    // dfs algorithm used to solve this problem
    void dfs(int row, int col, int intcolor, int newColor,vector<vector<int>>& image,
    vector<vector<int>>& ans, int delrow[], int delcol[]){

        int n = image.size();
        int m = image[0].size();
        // color the section 
        ans[row][col] = newColor;

        // traversal 4 - directionally we use a lop 
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // we want new row and new col ( simply we can say we want to clear section which have intail color like 1)

            /*  1. can be valid range in matrix
                2. can have intail color
                3. can not assign already if alrady done then NO*/
            if(nrow >=0 && nrow <n && ncol >=0 && ncol< m && ans[nrow][ncol] != newColor && image[nrow][ncol] == intcolor){
                dfs(nrow,ncol,intcolor,newColor,image,ans,delrow,delcol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // find out the initall color according to questions
        int intcolor = image[sr][sc];
        // will create copy matrix, we don't want to modify orignal data ( matrix )
        vector<vector<int>> ans = image;
        // dfs call ! offcouse you can use DFS/BFS

        // for > it is not 4-directionally connected to the starting pixel.
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        dfs(sr,sc,intcolor,color,image,ans,delrow,delcol);
        return ans;
    }
};
