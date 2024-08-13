class Solution {
public:
    vector<vector<int>>ans;
    int n ;
    void solve(int ind,int n,vector<int>&nums,int tar,vector<int>&st){
        if(tar==0){
            ans.push_back(st);
            return ;
        }  
        if(ind>=n || tar<0 )return ;

        int prev = -1;
        for(int i =ind;i<n;++i){
            if(prev==nums[i])continue;
            st.push_back(nums[i]);
            solve(i+1,n,nums,tar-nums[i],st);
            st.pop_back();
            prev = nums[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>st;
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,n,candidates,target,st);
        return ans;
    }
};