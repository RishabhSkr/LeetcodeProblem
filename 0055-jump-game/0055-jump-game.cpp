class Solution {
public:
// bool dp[10001];
// bool solve(int ind,int n,vector<int>&nums){
//     if(ind==n-1)return true;
//     if(nums[ind]==0)return false;
//     if(dp[ind]!=-1)return dp[ind];
//     int reach = ind+nums[ind];
//     for(int steps = ind+1;steps<=reach;++steps){
//         if(steps<n && solve(steps,n,nums))return dp[ind]=true;
//     }
//     return dp[ind]=false;
// }
    bool canJump(vector<int>& nums) {
        int n =nums.size();
// logic : at every step you steps should be increasing means to reach goal you should be increment in prev step. Greedy : at evry ind store max step you can take it >=n-1 it means you can reach  step.
       //it shows at max what index can I reach.
        //initially I can only reach index 0, hence
        int reach = 0;
        for(int idx = 0;idx<n;++idx){
             //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
             //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            reach = max(reach,idx+nums[idx]);
        }
        return true;
    }
};