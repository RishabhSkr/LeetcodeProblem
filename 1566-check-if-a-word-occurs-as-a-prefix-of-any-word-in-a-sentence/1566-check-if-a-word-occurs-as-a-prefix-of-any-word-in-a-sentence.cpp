class Solution {
public:
    int isPrefixOfWord(string sent, string pat) {
        // i,j i-> each word in sentence, jth wil point searchWord
        // each word  in sentence-> (w[i]==s[j]++)
        // if(j==n)return true;
        int n = sent.size();
        int patSize=pat.size();
        string word = "";
        int k =0;
        int ind =1;
        for(;k<n;++k){
            
           if(sent[k]==' '){
            if(word.size()>=patSize && word.substr(0,patSize)==pat)return ind;
            word= "";
            ind++;
           }else{
            word+=sent[k];
           }
        }
        if(word.size()>=patSize && word.substr(0,patSize)==pat)return ind;
        return -1;
    }
};