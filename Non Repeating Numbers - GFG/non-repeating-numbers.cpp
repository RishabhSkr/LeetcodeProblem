//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // vector<int> sortele(vector<int>&arr){
    //     sort(arr.begin(),arr.end());
    //     vector<int>ans;
    //     for(int i =0 ; i<arr.size()-1 ; i+=2){
    //         if(arr[i]!=arr[i+1])ans.push_back(arr[i]),i=-1;
    //     }
    //     if(ans.size()==1)ans.push_back(arr[arr.size()-1]);
        
    // }
    vector<int> singleNumber(vector<int> nums) 
    {
        // apporach: 1 use hashmaps // or sets 
        // approach: 2 sort elements and compare the adjacent elements nlogn
        // approach 3: use xor of bits// bit manipulation
        // set<int>st;
        // for(auto x : nums){
        //     auto it = st.find(x);
        //     if(it!=st.end())st.erase(it);
        //     else st.insert(x);
            
        // }
        // vector<int>ans(st.begin(),st.end());
        // return ans;
        // return sortele(nums);
        
        
        // approach 2 :  Using the concept of setBits if one number is present then take xor of all elements
        // Here we have to find two numbers then you have to take xor with setbit having one and setbits zero
    
        int x =0,setBits =0,first = 0,second = 0;
        for(auto y : nums)x^=y;
        for(int i=0 ;i<=32;++i){
            int num = 1<<i;
            if(x&num){
                setBits=num;
                break;
                
            }
        }
        for(auto x: nums){
            if(setBits&x)first ^= x;
            else second ^= x;
        }
        if(first<=second) return {first,second};
        return {second,first};
    }
    
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends