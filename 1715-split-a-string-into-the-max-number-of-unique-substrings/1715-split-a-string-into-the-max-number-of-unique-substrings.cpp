class Solution {
public:
    // use backtracking apporach and push it into set
    unordered_set<string>st;
    int ans= 0;
    void solve(string &s,int i){
        if(i==s.size()){
           ans = max((int)st.size(),ans);
            return ;
        }
        string op = "";
        for(int ind = i;ind<s.size();++ind){
            op.push_back(s[ind]);
            if(st.find(op)==st.end()){
                st.insert(op);
                solve(s,ind+1);
                st.erase(op);
            }
        }
    }
    int maxUniqueSplit(string s) {
        solve(s,0);
        return ans;    
    }
};