class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp1,mp2;
        string str="";
        for(char ch: s1){
            if(ch==' '){
                mp1[str]++;
                str = "";
            }else{
                str+=ch;
            }
        }
        mp1[str]++;
        str = "";
        for(char ch: s2){
            if(ch==' '){
                mp2[str]++;
                str="";
            }else{
                str+=ch;
            }
        }
        mp2[str]++;
        vector<string>ans;
        for(auto [word,f] : mp1){
            if(mp2.count(word)==0 && f==1)ans.push_back(word);
        }
         for(auto [word,f] : mp2){
            if(mp1.count(word)==0 && f==1)ans.push_back(word);
        }
        return ans;
    }
};