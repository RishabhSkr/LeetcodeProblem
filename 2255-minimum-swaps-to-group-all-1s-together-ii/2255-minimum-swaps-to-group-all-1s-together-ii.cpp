class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int i =0,j =0;
        int n = nums.size();
        int totalOne = 0;
        for(auto x : nums)if(x==1)totalOne++;
        int currOne = 0;
        // min(totalOne-currOne)
        int ans = INT_MAX;
        while(j<2*n){ // assume you have 2n elements for circular array
            if(nums[j%n]==1)currOne++;
            if(j-i+1>totalOne){
                if(nums[i%n]==1)currOne--;
                i++;
            }
            ans = min(totalOne-currOne,ans);
            j++;
        }
        return ans;
    }
};