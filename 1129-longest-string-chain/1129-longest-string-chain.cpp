class Solution {
public:
    bool compare(string &s1,string &s2){  // s1>s2
        int len1 = s1.size(),len2= s2.size();
        if(abs(len1-len2)!=1)return false;
        int i =0,j =0;
        while(i<len1){
            if(s1[i]==s2[j]){
                i++,j++;
            }
            else{
                i++;
            }
        }
        // edge case : abc adbc this works but in this case ->abc aef so ek sath pointer null hga
        if(i==len1 && j==len2)return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n =words.size();
        sort(words.begin(),words.end(),[&](string a,string b){return a.size()<b.size();});
        vector<int>dp(n,1);

        for(int i = 1;i<n;i++){
           for(int j = i-1;j>=0;--j){
                if(compare(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]= 1+dp[j];
                }
           }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};