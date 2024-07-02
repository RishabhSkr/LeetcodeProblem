class Solution {
public:
       // logic using mp[num]>0 and mp.count>0 not doing mp.erase(num) if cnt ==0 gives wrong res
        // because mp.count(num) becomes true even if freq ==0 and return true val because key is present.Hence we need to delete the if freq of num is zero from map
        // mp[num]>0 it gives correct res freq always be >0 then dec and add to the res. 
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        
        for(int &num : nums1) {
            mp[num]++;
        }

        vector<int>result;
        for(int i = 0; i < nums2.size();i++) {
            int num = nums2[i];

            if(mp[num] > 0) {
                mp[num]--;
                result.push_back(num);
            }
        }

    return result;
        
    }
};