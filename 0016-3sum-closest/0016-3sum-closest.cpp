class Solution {
public:
    // sort array
    //   i,j,k
    // diff  min kro ans 
    int threeSumClosest(vector<int>& nums, int tar) {
        sort(nums.begin(),nums.end());
        int ans =0;
        int n = nums.size();
        int minDiff = INT_MAX;
        for(int i =0;i<n-2;++i){ // n-2
            int j = i+1,k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==tar)return sum;  // sum return krna tha na ki ans
                int currDiff = abs(tar-sum);
                if(currDiff<minDiff){
                    minDiff = currDiff;
                    ans = sum;
                }
                if(sum<tar)j++; 
                if(sum>tar)k--;
            }
        }
        return ans; 
    }
};