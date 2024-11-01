class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3)return s;
        string str = "";
        int cnt = 1;
        str+=s[0];
        for(int i = 1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else cnt=1;
               
        // Add the character if there are less than two consecutive identical characters
            if(cnt < 3) {
                str += s[i];
            }
        }
        return str;
    }
};