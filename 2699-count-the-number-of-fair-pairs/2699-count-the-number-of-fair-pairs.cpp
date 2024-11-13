class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long cnt1 = 0, cnt2 = 0;

        // Count pairs where sum is <= upper
        int s = 0, e = n - 1;
        while (s < e) {
            while (s < e && nums[s] + nums[e] > upper) {
                e--;
            }
            cnt1 += (e - s);
            s++;
        }

        // Count pairs where sum is < lower
        s = 0;
        e = n - 1;
        while (s < e) {
            while (s < e && nums[s] + nums[e] >= lower) {  // Use >= to exclude pairs that meet lower bound
                e--;
            }
            cnt2 += (e - s);
            s++;
        }

        return cnt1 - cnt2;  // No need for abs as cnt1 >= cnt2 by construction
    }
};
