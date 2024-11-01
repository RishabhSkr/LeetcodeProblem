class Solution {
public:
    int n, m;
    // int solve(int i,int j,vector<int>nums1,vector<int>nums2){
    //     if(i==n)return 0;
    //     if(j==m)return 0;

    //     int take =0;
    //     if(nums1[i]==nums2[j])take = 1+solve(i+1,j+1,nums1,nums2);
    //     int notTake = max(solve(i,j+1,nums1,nums2) ,
    //     solve(i+1,j,nums1,nums2)); return max(take,notTake);
    // }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
          int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    maxLength = max(maxLength, dp[i + 1][j + 1]);
                } else {
                    dp[i + 1][j + 1] = 0; // Reset to 0 as it's a subarray, not subsequence
                }
            }
        }

        return maxLength;
    }
};