//48. Rotate Image
#include <bits/stdc++.h>
using namespace std;

/*
Approach - Optimization 
1- Tranpose the matrix
2- Reverse the every row given after tranposing the matrix

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reversing each row of the matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
