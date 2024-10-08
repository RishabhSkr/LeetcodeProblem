class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        stack<char>st;
        if(s.length()%2!=0)return 0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
                if(ch=='[')st.push(ch);
            else{
                // ch is closing brackets
                if(!st.empty() and st.top()=='[')st.pop();
                else st.push(ch);                
            }

        }
        
        // invalid parenthsis
         int a=0,b=0;
                while(!st.empty()){
                    if(st.top()=='[')a++;
                    else b++;
                    st.pop();
                }
                ans=(a+1)/2;
        return ans;
    }
};