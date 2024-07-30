class Solution {
public:
    int minimumDeletions(string s) {
        stack<int>st;
        int cnt = 0;
        for(auto ch : s){
            if(!st.empty() && st.top()=='b' && ch=='a'){
                cnt++;
                st.pop();
            }
            else st.push(ch);
        }
        return cnt;
    }
};