class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Calculate window sums
        vector<int> windowSums;
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        windowSums.push_back(sum);
        
        for(int i = k; i < n; i++) {
            sum = sum + nums[i] - nums[i-k];
            windowSums.push_back(sum);
        }
        
        // Step 2: Calculate left best positions
        vector<int> left(windowSums.size(), 0);
        int bestSum = windowSums[0];
        
        for(int i = 1; i < windowSums.size(); i++) {
            if(windowSums[i] > bestSum) {
                bestSum = windowSums[i];
                left[i] = i;
            } else {
                left[i] = left[i-1];
            }
        }
        
        // Step 3: Calculate right best positions
        vector<int> right(windowSums.size(), 0);
        bestSum = windowSums.back();
        right.back() = windowSums.size()-1;
        
        for(int i = windowSums.size()-2; i >= 0; i--) {
            if(windowSums[i] >= bestSum) {
                bestSum = windowSums[i];
                right[i] = i;
            } else {
                right[i] = right[i+1];
            }
        }
        
        // Step 4: Find best combination
        int maxTotal = 0;
        vector<int> result = {0, 0, 0};
        
        for(int i = k; i < windowSums.size()-k; i++) {
            int leftIdx = left[i-k];
            int rightIdx = right[i+k];
            int total = windowSums[leftIdx] + windowSums[i] + windowSums[rightIdx];
            
            if(total > maxTotal) {
                maxTotal = total;
                result = {leftIdx, i, rightIdx};
            }
        }
        
        return result;
    }
};