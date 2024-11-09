class Solution {
public:
    long long minEnd(int n, int x) {
        long long start = x;
        for(int i =2;i<=n;++i){
            start=(start+1)|x;
        }
        return start;
     
    }
};