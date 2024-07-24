class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // mapping se store kr lo index and converted integer and then sort kr lo index ke according
        int n = nums.size();
        vector<pair<int, int>> mp;

        for (int i = 0; i < n; ++i) {
            string str = to_string(nums[i]);
            string num = "";
            for (char ch : str) {
                num += to_string(mapping[ch - '0']);
            }
            mp.emplace_back(stoi(num), i);
        }
        sort(mp.begin(),mp.end());
        vector<int>res;
        for(auto x : mp){
            res.push_back(nums[x.second]);
        }
        return res;
        
    }
};