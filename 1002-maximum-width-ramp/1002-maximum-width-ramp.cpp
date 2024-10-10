class Solution {
public:
/*
Plan-> we need to maximise j-i but with condition nums[i] <=nums[j] && i<j
    what if we sort indice of nums acc to nums values this will always nums[i]<=nums[j] hold
    now if we have to check i<j and maximise (j-i)  we not i is min ind and j max ind->
    iterate of sort ind and store minInd with i and maximis j-i
*/
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>ind(n);
        for(int i =0;i<n;++i)ind[i]=i;

        sort(ind.begin(), ind.end(), [&](int i, int j) {
            if (nums[i] == nums[j]) return i < j;
            return nums[i] < nums[j];
        });

       int minInd = n;
       int maxi =0;
       for(int i =0;i<n;++i){
            maxi = max(maxi,ind[i]-minInd);
            minInd = min(minInd,ind[i]);
       }
        return maxi;
    }
};