class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = 0;
        int res = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            curr+=nums[i];
            if(curr<0){
                curr = 0;
            }
            res = max(res,curr);
        }
        curr = 0;
        int ans = 0;
        for(int i=0;i<n;++i){
            curr+=nums[i];
            if(curr>0){
                curr = 0;
            }
            ans = min(ans,curr);
        }
        res = max(abs(ans),res);
        return res;
    }
};