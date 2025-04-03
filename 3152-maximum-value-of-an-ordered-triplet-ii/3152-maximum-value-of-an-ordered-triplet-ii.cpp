class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0,maxDiff = 0,maxTriplet=0;
        for(long long no : nums){
            maxTriplet= max(maxTriplet,maxDiff*no);
            maxDiff = max(maxDiff,maxi-no);
            maxi = max(maxi,no);
        }
        return maxTriplet;
    }
    
};