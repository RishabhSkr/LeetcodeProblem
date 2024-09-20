class Solution {
public:
    vector<int> getlps(string pattern){
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
        vector<int>lps(M,0);
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        string  rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s+"$"+rev;
        vector<int>lps = getlps(temp); // O(n)
        int lpsLen = lps.back();
        string needTobeAdded = rev.substr(0,rev.length()-lpsLen);
        return needTobeAdded+s;
        
    }
};