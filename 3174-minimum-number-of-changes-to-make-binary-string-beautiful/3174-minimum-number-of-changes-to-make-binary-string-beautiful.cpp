class Solution {
public:
    int minChanges(string s) {
     int cnt = 0;
     int n = s.size();
     for(int i =0;i+1<n;i+=2){
        if(s[i]!=s[i+1])cnt++;
        
     }
     return cnt;   
    }
};