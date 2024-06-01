class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorVal= start^goal;
        int cnt = 0;
        while(xorVal){
            if(xorVal&1)cnt++;
            xorVal>>=1;
        }   
        return cnt;
    }
};