class Solution {
public:
vector<string> ans;
void solve(int i, int n, string &s) { // yuo are not passing as refrence so ypu dont need to modify it. you are sharing the mutable state of s to diff recursive calls.
    if (i == n) {
        ans.push_back(s);
        return;
    }
    s+="1";
    solve(i + 1, n, s);
    s.pop_back();
    
    if (s.empty() || s.back() == '1') { // only add when s is empty or s back val is 1
        s+="0";
        solve(i + 1, n,s);
        s.pop_back();
    }
}

    vector<string> validStrings(int n) {
        string s ="";
        solve(0, n, s);
        return ans;
    }
};