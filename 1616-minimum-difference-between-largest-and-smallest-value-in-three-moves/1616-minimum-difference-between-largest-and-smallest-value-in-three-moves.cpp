class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<5)return 0;
        int ans =INT_MAX;
            // 3 moves ka use piche ele ko change krne me laga do.max ele n-4 pr hga
            // ans = min(ans,nums[n-3-1]-nums[0]);
            // ans = min(ans,nums[n-2-1]-nums[1]);
            // ans = min(ans,nums[n-1-1]-nums[2]); // 2 front aur 1 piche
            // ans = min(ans,nums[n-0-1]-nums[3]); // 3 moves me 0 1 2 ko change 4th elem min hga
             int cnt =3;
             for(int i =0;i<4;++i){
                ans = min(ans,nums[n-1-cnt]-nums[i]);
                cnt--;
             }
        return ans;
    }
};