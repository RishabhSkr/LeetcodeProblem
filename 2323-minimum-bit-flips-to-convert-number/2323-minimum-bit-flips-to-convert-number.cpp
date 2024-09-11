class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorValue = start^goal;
        if(goal==start)return 0;
        int cnt =0;
        while(xorValue){
            if(xorValue&1)cnt++;
            xorValue>>=1;
        }
        return cnt;
    }
};