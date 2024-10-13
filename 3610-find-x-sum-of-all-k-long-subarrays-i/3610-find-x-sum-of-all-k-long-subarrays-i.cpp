class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>res;

        for (int i = 0; i <nums.size()-k+1; ++i) {
            unordered_map<int, int> f;
            for (int j = i; j <i+k; ++j) {
                f[nums[j]]++;
            }
            int curr = 0;
            vector<pair<int,int>>mp(f.begin(),f.end());
            sort(mp.begin(), mp.end(), compare);
            int m = mp.size();
            for(int ii=0;ii<min(m,x);++ii){
                curr+=mp[ii].first*mp[ii].second;
            }
            res.push_back(curr);
        }

        return res;
    }
};