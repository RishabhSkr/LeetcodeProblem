class Solution {
public:
    int isPossible(int i, int n, vector<int> &nums, vector<int> &store){
        if(i==n-1) return 1;
        if(store[i]!=-1) return store[i];
        for(int j= i+1; j<=i+nums[i];j++){
            if(isPossible(j,n,nums,store)) return store[i]=1;

        }
        return store[i]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> store(nums.size(),-1);
        return isPossible(0,nums.size(),nums,store);

    }
};