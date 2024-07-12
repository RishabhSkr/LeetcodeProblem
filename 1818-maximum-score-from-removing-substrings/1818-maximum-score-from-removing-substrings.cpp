class Solution {
public:
    string removeChar(string &str,string &pat){
        stack<char>st;
        for(char &ch: str){
            if(!st.empty() && pat[1] == ch && st.top() == pat[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string rem = "";
        while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
        }
        reverse(rem.begin(),rem.end());
        return rem;
    }
    int maximumGain(string s, int x, int y) {
    // logic;
    // example s = baba : x>y ab+ba(x+y): ba + ba(y+y)=> x+y>2y always since gready + stack
    // take max profit first then min 
        int n = s.length(),res =0;
        string maxPatt = (x > y) ? "ab" : "ba";
        string minPatt = (x > y) ? "ba" : "ab";
        int maxProfit = max(x, y);
        int minProfit = min(x, y);
        // first pass
        string remString = removeChar(s,maxPatt);
        int charRemoved = n-remString.length();
        res += (charRemoved/2)*maxProfit;
        // 2 pass
        string str = removeChar(remString,minPatt);
        charRemoved = remString.length()-str.length();
        res += (charRemoved/2)* minProfit;
        return res;
    }
};