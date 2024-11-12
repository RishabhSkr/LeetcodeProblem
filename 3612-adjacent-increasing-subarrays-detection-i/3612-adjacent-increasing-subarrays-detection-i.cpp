class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i =0;i<=n-2*k;++i){
            bool flag = true;

            for(int j = i;j<i+k-1;++j){
                if(nums[j+1]<=nums[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                bool flag2 = true;
                for(int j= i+k;j<i+2*k-1;++j){
                  
                    if(nums[j+1]<=nums[j]){
                        flag2 = false;
                        break;
                    }
                }
                if(flag2)return true;
            }
        }

        return false;
    }
};
