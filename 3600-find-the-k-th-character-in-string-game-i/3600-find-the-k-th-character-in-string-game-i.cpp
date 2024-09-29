class Solution {
public:
    char kthCharacter(int k) {
        string s ="a";
        int len = 1;
        char ans ='a';
        while(len<k){
            string s1 = "";
            for(auto ch:s){
                s1+=(ch+1);
            }
            s+=s1;
            len = s.size();
        }
        for(int i=0;i<s.size();++i){
            if(i+1==k){
                ans= s[i];
                break;
            }
        }
        return ans;
    }
};