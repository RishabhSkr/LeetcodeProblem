class Solution {
public:
   // logic cnt kron consecutive element jbtk mil rha h jaise window ki size k ya ussse badi hui max element i-k+1 pos pr curr max consecutive element hga and nhi hua to -1 reset kr do window and consecutive size ko 1.[1,2,3,4,3,2,5], k = 3
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)return nums;
        vector<int>res(n-k+1,-1);
        int cntCons =1;
        for(int i =1;i<n;++i){
            if(nums[i-1]+1==nums[i]){
                cntCons++;
                if(cntCons>=k)
                    res[i-k+1]=nums[i];
            }
            else cntCons =1;
        }
        return res;
    }
};