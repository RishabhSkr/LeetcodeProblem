class Solution {
public:
int solve(vector<int>&nums,int k){
    int n= nums.size();
      int i =0,j=0,sum =0,ans=0;
        while(j<n){
            sum+=(nums[j]%2);
            while(sum>k){  // we shoould be have while loop because here we subarray adding to ans <=k ans. wee need to add when subarray size ==k exactly
                sum-=(nums[i]%2);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
}
// After replacing each even by zero and every odd by one can we use prefix sum to find answer
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // two Pointer
        return solve(nums,k)-solve(nums,k-1); // we need exactly k numbers
    //    unordered_map<int,int>preSum;//prefixSum,cnt
    //     int prefixSum = 0;
    //     preSum[0]=1; // intitally set sum =0 into map as prefixSum==0 
    //     int cnt =0;
    //     for(int j =0;j<n;++j){
    //         prefixSum+=(nums[j]%2);
    //         // find prefixSum-k
    //         cnt+=preSum[prefixSum-k];       
    //         preSum[prefixSum]++;
    //     }
    }
};