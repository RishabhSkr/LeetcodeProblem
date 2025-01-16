class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; ++i) {
            mp[nums1[i]]+=n2;
        }
        for (int i = 0; i < n2; ++i) {
            mp[nums2[i]]+=n1;
        }
        int ans =0;
        for (auto [x, f] : mp) {
            if(f%2==0)continue;
            ans^=x;
        }
        return ans;
    }
};