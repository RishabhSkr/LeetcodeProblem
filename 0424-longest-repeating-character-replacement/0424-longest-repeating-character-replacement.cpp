class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.length();
        int maxLen =0;
        // brute force O(n^2) T.C O(26)
            int  i= 0;
            int hash[26]={0};
            int maxFreq=0;
            for(int j =0;j<n;++j){
                hash[s[j]-'A']++;
                maxFreq = max(maxFreq,hash[s[j]-'A']);
                int currLen = max(j-i+1,maxLen);
                int changes = currLen - maxFreq ;
                if(changes>k){
                    hash[s[i]-'A']--;
                    i++;
                }
                maxLen = max(j-i+1,maxLen);
            }
        
        return maxLen;
    }   
};