//39. Combination Sum

// now here you have choice to include this element again!
// that is why we are not including ( index + 1 ) 
// because we are waiting for next process

// thank you sane!
// happy coding


class Solution {
private: 
    void Helper(int index, int target, vector<int>& candidates, vector<int>& arr, vector<vector<int>>& result){
        // base condtion: when eat the things then capacity 0 and if visted complete array
        if(index == candidates.size()){
            if(target == 0){
                result.push_back(arr);
            }
            return;
        }
        // we are including the element
        if(candidates[index] <= target){
            arr.push_back(candidates[index]);
            // we have multiple choice to include same value multiple times, you are not going to incease index value 
            // index says : i am here , i'm waiting for next including process
            Helper(index,target-candidates[index], candidates, arr, result);
            // because we want all possible solution - we will remove the value
            // you can make - recusive tree and choice diagram to understand better way!
            arr.pop_back();
        }
        // we are not including the element
         Helper(index+1,target, candidates, arr, result);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> resultArray;
        vector<int> arr;
        int index = 0;
        Helper(index,target, candidates, arr, resultArray);
        // you can return -  ou may return the combinations in any order.
        return resultArray;
    }
};
