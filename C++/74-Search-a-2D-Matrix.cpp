class Solution {
	
	// search an element if exist into the matrix 
	// approach - 1 use linear search
	// approach - 2 use two pointer algoritm
	// aproach - 3 use binary search 

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix[0].size() - 1;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        while( start >= 0 && start< n && end >= 0 && end < m){
            if(matrix[start][end] == target){
                return true;
            }else if(matrix[start][end] > target){
                end--;
            }else if(matrix[start][end] < target){
                start++;
            }
        }
        return false;
    }
};

