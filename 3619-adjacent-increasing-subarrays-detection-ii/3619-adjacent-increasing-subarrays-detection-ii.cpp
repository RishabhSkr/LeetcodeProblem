class Solution {
public:
    bool isValid( int n, vector<int>& arr, int k) {
        for (int i = 0; i <= n - 2 * k; i++) {
            if (arr[i] >= k && arr[i + k] >= k) {
                return true;
            }
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
         int n = nums.size();

        vector<int>arr(n+1,1);
        for(int i =n-2;i>=0;--i){
            if(nums[i+1]>nums[i])arr[i]=arr[i+1]+1;
            else arr[i]=1;
        }
        int maxi = 0;

        int lo = 1,hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isValid(n,arr,mid)){
                maxi =mid;
                lo = mid +1;
            }else hi = mid-1;
        }
      
        return maxi;
    }
    
   
};