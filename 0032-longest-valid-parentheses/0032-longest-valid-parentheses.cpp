class Solution {
public:
    int longestValidParentheses(string s) {
      // greedy-> go to left to right check if cl>op op==cl =0
      //         go to right to left check if op>cl op==cl=0
      int n = s.size();

      int  i =0;
      int op = 0,cl = 0;
      int ans = 0;
        // left to right 
        while(i<n){
            if(s[i]=='(')op++;
            else cl++;
            if(cl>op){
                op=0;
                cl =0;
            }else if(cl==op){
                ans = max(ans ,cl*2);
            }
            i++;
        }
        op=cl=0;
        i = n-1;
        int ans2 =0;
      // right to left
      while(i>=0){
        if(s[i]=='(')op++;
        else cl++;
        if(op>cl){
            op=0;
            cl =0;
        }else if(cl==op){
            ans2 = max(ans2 ,cl*2);
        }
        i--;
      }
      return max(ans,ans2);
    }
};