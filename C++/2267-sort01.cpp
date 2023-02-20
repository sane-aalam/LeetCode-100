class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // remember the point start jo hay appna wo end say zada na ho jaye check laga 
        int start = 0;
        int end = n -1;
        
        while(start<end){
            
            if(arr[start] == 0 && start<end){
                start ++;
            }
            if(arr[end] == 1 && start<end){
                end --;
            }
            
            if(arr[start]!=0 && arr[end] != 1 && start<end){
                swap(arr[start], arr[end]);
                    start++;
                    end--;
            }
        }
        
    }
};
