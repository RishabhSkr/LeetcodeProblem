class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2) return false;
        int balance = 0;
        // left to right check it is balance-> if locked==0 or op balance vice versa for closing brack from right to left
        for(int i =0;i<n;++i){
            if(locked[i]=='0' || s[i]=='(')balance++;
            else balance--;
            if(balance<0)return false;
        }

        // for closing
        balance =0;
        for(int i =n-1;i>=0;--i){
            if(locked[i]=='0' || s[i]==')')balance++;
            else balance--;
            if(balance<0)return false;
        }
        return true;
    }
};