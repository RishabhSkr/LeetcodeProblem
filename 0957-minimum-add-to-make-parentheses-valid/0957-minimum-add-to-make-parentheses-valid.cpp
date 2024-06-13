class Solution {
public:
    int minAddToMakeValid(string s) {
        int count =0,neg =0;
        int n =s.length();
        for(int i =0;i<n;++i){
            if(s[i]=='(')count++;
            else count--;
            if(count<0){
                neg++;
                count=0;
            }
      
        }
        return abs(count+neg);
    }
};