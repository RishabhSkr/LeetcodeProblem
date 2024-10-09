class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0;
        int need = 0;
        for(auto  x: s){
            if(x=='(')op++;
            else{
                op--;
                if(op<0){
                    need++;
                    op=0;
                }
            }
        }
        return op+need;
    }
};