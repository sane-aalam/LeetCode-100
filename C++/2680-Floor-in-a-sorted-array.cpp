//Floor in a Sorted Array 
// aksed - @microsoft + amazon 

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
         if(v[0]>x) 
        return -1;
        
        else if(v[0]==x)
        return 0;
        
        int start = 0, end = n-1;
        
        while(start<=end){
            int mid = (start) + (end-start)/2;
            if(v[mid] == x){
                return mid;
            }
            else if(v[mid]>x){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return (start-1);
    }
};

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}

