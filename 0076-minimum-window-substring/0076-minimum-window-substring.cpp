class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if (n < m) return ""; // If s is shorter than t, return empty string
        
        int startInd = -1, maxLen = INT_MAX;
        int i = 0;
      
        unordered_map<char, int> mp;
        for (auto x : t) mp[x]++;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (mp[s[j]] > 0)cnt++; 
            mp[s[j]]--;
            while (i<=j && cnt == m) {
                if (maxLen > j - i + 1) {
                    maxLen = j - i + 1;
                    startInd = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) cnt = cnt - 1; // we left out some characters in t
                i++;
            }
        }
        
        return (startInd != -1) ? s.substr(startInd, maxLen) : "";
    }
};
