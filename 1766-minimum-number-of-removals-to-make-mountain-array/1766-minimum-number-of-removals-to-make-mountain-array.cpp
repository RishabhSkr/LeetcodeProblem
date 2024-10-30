class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = n;  // Initialize ans with maximum possible removals, as we will minimize it

        // Step 1: Calculate LIS (Longest Increasing Subsequence) from left to right
        vector<int> lis(n, 1);  // Each element alone is a sequence of length 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Step 2: Calculate LDS (Longest Decreasing Subsequence) from right to left
        vector<int> lds(n, 1);  // Each element alone is a sequence of length 1
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // Step 3: Calculate the minimum removals for forming a valid mountain array
        for (int i = 1; i < n - 1; ++i) {
            // Ensure we have a valid peak (both lis[i] > 1 and lds[i] > 1)
            if (lis[i] > 1 && lds[i] > 1) {
                int mountainLength = lis[i] + lds[i] - 1;
                ans = min(ans, n - mountainLength);  // Update minimum removals needed
            }
        }

        return ans;
    }
};
