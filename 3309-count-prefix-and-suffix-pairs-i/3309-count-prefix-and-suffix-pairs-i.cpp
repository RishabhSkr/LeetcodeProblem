class Solution {
public:
    bool isPrefixSuffix(string str1,string str2){
        if(str1.size()>str2.size())return false;
        int j =0,i=0;

        while(i<str1.size()){
            if(str1[i++]!=str2[j++]){
              return false;
            }
            if(i==str1.size())break;
        }

        i =str1.size()-1,j= str2.size()-1;
         while(i>=0){
            if(str1[i--]!=str2[j--]){
              return false;
            }
            if(i<0)break;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n =words.size(),cnt =0;
        for(int i = 0 ;i<n-1;++i){
            string str1 = words[i];
            for(int j =i+1 ;j<n;++j){
                string str2 = words[j];
                if(isPrefixSuffix(str1,str2))cnt++;
            }
        }
        return cnt;
    }
};