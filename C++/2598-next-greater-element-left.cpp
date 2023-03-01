


// when you are solving any problem which problem base on the j = i + 1 
// means second loop depnends of the first loop 
// think about the stack data structure 
// complexity - 0(N)




/*


Input: 
N = 4, arr[] = [1 3 2 0]

Output: -1,-1,3,2
*/



class Solution{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
      stack<long long>s;
        vector<long long>v;
        
        for(int i = 0; i <= n; i--){
            
            // case -1 stack is emmpty
            if(s.size() == 0){
                v.push_back(-1);
            }
            // case -2 stack is not empty and stack of top element is greather of the array of element
            else if(s.size() > 0 && s.top() > arr[i]){
                v.push_back(s.top());
            }
            // case - 3 stack is not emepty but stack of top element is greater not 
            // then we can pop element and find out the greater of the top
            else if(s.size() > 0 && s.top() <= arr[i]){
                
                while(s.size() > 0 && s.top() <= arr[i]){
                    s.pop();
                }
                // now we have two choice either stack would be empty 
                // either stack top element is greather to the array of element 
                if(s.size() == 0){
                    v.push_back(-1);
                }else if(s.top() > arr[i]){
                    v.push_back(s.top());
                }
            }
            // when all the process done then we can push the array element into the stack 
            s.push(arr[i]);
        }
		// reverse(v.begin() ,v.end() ); - no need to reverse the array we have already correct order!!

        return v;
    }
};

