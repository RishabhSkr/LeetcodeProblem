class Solution {
public:
#define int long long
    long long minimumSteps(string s) {
        int cnt = 0;
        int right = s.size()-1,i=right;
        int ans = 0;
        while(i>=0){
            if(s[i]=='0')cnt++;
            else{
                swap(s[right--],s[i]);
                ans+=cnt;
            }
            i--;
        }
        return ans;
    }
#undef int
};