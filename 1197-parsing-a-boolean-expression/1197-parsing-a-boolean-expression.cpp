class Solution {
public:

bool parse_or(vector<int>&res){
    bool ans = res[0];
    for(auto x : res){
        ans|=x;
    }
    return ans;
}
 
 bool parse_and(vector<int>&res){
    bool ans = res[0];
    for(auto x : res){
        ans&=x;
    }
    return ans;
}  

 bool parseBoolExpr(string exp) {
        stack<char>st;
        bool ans =false;
        for(auto ch : exp){
            if(ch==',')continue;
            if(ch==')'){
                vector<int>res;
                while( st.top()!='!' && st.top()!='|' && st.top()!='&'){
                    char  c = st.top();
                    st.pop();
                    if(c=='f')res.push_back(0);
                    else if(c=='t')res.push_back(1);

                }
                char c = st.top();
                st.pop();

                if(c=='|'){
                    ans = parse_or(res);
                    if(ans)st.push('t');
                    else st.push('f');
                }
                else if(c=='&'){
                    ans = parse_and(res);
                    if(ans)st.push('t');
                    else st.push('f');
                }
                else if(c=='!'){  // not single res dega if not false h to true or true h to false
                    if(res[0]==0)st.push('t');
                    else st.push('f');
                }

            }
            else st.push(ch);

        }
        return st.top()=='t';      
    }
};

