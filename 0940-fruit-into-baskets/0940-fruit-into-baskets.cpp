class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>mp;
        int i = 0,maxLen = 0;
        if(nums.size()==1)return 1;
        else if(nums.size()==0)return 0;
        for(int j = 0;j<nums.size();++j){
            mp[nums[j]]++;
            if(mp.size()>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            if(mp.size()<=2)maxLen = max(maxLen,j-i+1);
            // cout<<maxLen<<endl;
        }
        return maxLen;
    }
};