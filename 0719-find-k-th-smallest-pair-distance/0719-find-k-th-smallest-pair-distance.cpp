class Solution {
public:
    int countPair(vector<int>&nums,int dif){
        int cnt = 0;
        // sldiing window
        int i =0,j =1,n = nums.size();
        while(j<n){
            while(i<n && nums[j]-nums[i]>dif)i++;
            cnt +=j-i;
            j++;
        }
        return cnt;
    }

    // binSearch + sliding window
    int smallestDistancePair(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lo  = 0,hi = nums[n-1]-nums[0];
        int ans =0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int cnt = countPair(nums,mid);
            if(cnt<k){
                
                lo = mid+1;
            }else {
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};