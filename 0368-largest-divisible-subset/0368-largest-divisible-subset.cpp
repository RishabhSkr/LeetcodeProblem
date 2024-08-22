class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1),hash(n,-1);

        for(int i = 1;i<n;i++){
           for(int j = i-1;j>=0;--j){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]= 1+dp[j];
                    hash[i]=j; // prev index when it is divisible 
                }
           }
        }

        int maxi = 0,endInd = 0;
        for(int i =0;i<n;++i){
            if(dp[i]>maxi){
                maxi = dp[i];
                endInd = i;
            }
        }
        vector<int> res;
        while (endInd != -1) {
            res.push_back(nums[endInd]);
            endInd = hash[endInd];
        }
        reverse(res.begin(), res.end()); // Reverse to get the correct order
        return  res;
    }
};