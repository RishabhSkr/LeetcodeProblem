class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int n = s.size();
        string ans ="";
        for(int i = 0; i < n; i++){
            if(s[i] != ')') {
                st.push(s[i]);
            }else{
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                // cout<<temp<<endl;
                for (int j = 0; j < temp.size(); j++) { // add to stack so reverse the whole
                    st.push(temp[j]);
                }
           }
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};