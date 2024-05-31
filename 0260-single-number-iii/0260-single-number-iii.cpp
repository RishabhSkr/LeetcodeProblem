class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // steps1: take a xor of all element: this will give xor of two unique element.
        // steps2: create a mask by taking (xor&-xor) this will give the rightmost set bits of two unique number
        // divide the element into two groups : using mask if their mask bit is same by taking and
        // take xor of individiual groups in which each unique element is present;
        long long xor_nums = 0;
        for(auto x : nums)xor_nums^=x;
        int mask = (xor_nums)&(-xor_nums);  /// finding the right most unset bit
        int groupA=0;
        int groupB=0;
        for(auto x : nums){
            if(x&mask)groupA^=x;
            else groupB^=x;
        }
        return {groupA,groupB};
    }
};