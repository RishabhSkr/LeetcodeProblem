class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int cnt  = s.length();
        for(auto &ch : s){
            if (!st.empty() && ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D'))){
                st.pop();
                cnt-=2;
            }else{
                st.push(ch);
            }
        }
        return cnt;
    }
};