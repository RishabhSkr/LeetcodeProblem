class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // find consecutive max element
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0,ans=0;
        bool found=false;
        for(int i =0;i<n;++i){
            if(maxi==nums[i]){
                cnt++;
                found = true;
                ans = max(cnt,ans);
                continue;
            }
            if(found){
                if(nums[i-1]==maxi && nums[i]==maxi){
                    cnt++;
                    ans = max(ans,cnt);
                }
                else{
                    found = false;
                    cnt =0;
                } 
            }
            
        }
        return ans;

    }
};