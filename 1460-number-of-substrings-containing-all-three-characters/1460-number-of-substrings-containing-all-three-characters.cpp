class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cntA = 0,cntB = 0,cntC = 0,cnt=0;
        int i=0;
        for(int j =0;j<n;++j){
            if(s[j]=='a')cntA++;
            if(s[j]=='b')cntB++;
            if(s[j]=='c')cntC++;
            while(cntA!=0 && cntB!=0&& cntC!=0){
                cnt+=n-j;
                if(s[i]=='a')cntA--;
                else if(s[i]=='b')cntB--;
                else cntC--;
                i++;
            }
           
        }
        return cnt;
    }
};