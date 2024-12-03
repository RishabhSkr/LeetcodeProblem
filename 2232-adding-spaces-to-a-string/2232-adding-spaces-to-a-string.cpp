class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        sort(spaces.begin(),spaces.end());
        int cnt =0;
        int n = spaces.size();
        int m = s.size();
        int j =0;
        for(int i =0;i<m;++i){
            if(j<n && spaces[j]==cnt){
                ans+=" ";
                j++;
            }
            ans+=s[i];
            cnt++;
        }
        return ans;
    }
};