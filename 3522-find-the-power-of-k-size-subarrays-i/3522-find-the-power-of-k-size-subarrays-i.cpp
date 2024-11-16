class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
     int n = nums.size();
     if(k==1)return nums;
    int cntCons=1;
     vector<int>res(n-k+1,-1);
     for(int i =1;i<n;++i){
        if(nums[i-1]+1==nums[i]){
            cntCons++;
            if(cntCons>=k)res[i-k+1]= nums[i];
        }else cntCons = 1;
     }   
     return res;
    }
};