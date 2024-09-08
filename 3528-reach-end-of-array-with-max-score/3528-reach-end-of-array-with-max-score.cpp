class Solution {
public:
#define  ll long long 

    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        stack<ll>st;
        vector<ll>NGR(n,n-1);
        for(ll i =n-1;i>=0;--i){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty() && nums[i]<nums[st.top()]){
                NGR[i]= st.top();
            }
            st.push(i);
        }
        ll maxi = 0;
        ll i= 0;
        while(i<n){

            if(NGR[i]==n-1){ // not found
                maxi += (n-1-i)*nums[i];
                break;
            }else{
                maxi+=((NGR[i]-i)*nums[i]);
                i = NGR[i];
            }
        }
        return maxi;
    }
};