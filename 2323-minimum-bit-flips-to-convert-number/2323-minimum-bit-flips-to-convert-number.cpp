class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorValue = start^goal;
        int cnt =0;
        while(xorValue){
            if(xorValue&1)cnt++;
            xorValue>>=1;
        }
        return cnt;
    }
};