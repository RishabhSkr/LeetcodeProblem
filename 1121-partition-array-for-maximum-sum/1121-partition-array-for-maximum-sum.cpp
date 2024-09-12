class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        for(int ind=n-1 ;ind>=0;--ind){
            int maxi = INT_MIN,len =0,ans = INT_MIN;
            for(int j =ind;j<=min(ind+k-1,n-1);++j){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len*maxi + dp[j+1];
                ans = max(ans,sum);
            }
            dp[ind]=ans;
        }
        return dp[0];
    }
};