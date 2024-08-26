class Solution {
public:
    string makeDigit(int num, int digits) {
        string s = to_string(num);
        int n = s.size();
        for(int i=0;i<digits-n;i++)
            s = "0" + s;
        return s;
    }

    unordered_set<string> make4Swap(int num, int maxLen) {
        string s = makeDigit(num, maxLen);
        unordered_set<string> st;
        st.insert(s);
        for (int i = 0; i < maxLen; ++i) {
            for (int j = i + 1; j < maxLen; ++j) {
                // First swap
                swap(s[i], s[j]);
                st.insert(s);
                for (int i1 = 0; i1 < maxLen; ++i1) {
                    for (int j1 = i1 + 1; j1 < maxLen; ++j1) {
                        if (s[i1] != s[j1]) { // char not same then swap it
                            // Second swap
                            swap(s[i1], s[j1]);
                            st.insert(s);
                            swap(s[i1], s[j1]);
                        }
                    }
                }
                swap(s[i], s[j]);
            }
        }
        return st;
    } 

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int maxDigit = to_string(*max_element(nums.begin(), nums.end())).size();
        unordered_map<string, int> mp;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (auto& s : make4Swap(nums[i], maxDigit)) {
                if (mp.count(s)) ans += mp[s];
            }
            mp[makeDigit(nums[i], maxDigit)]++;
        }
        return ans;
    }
};