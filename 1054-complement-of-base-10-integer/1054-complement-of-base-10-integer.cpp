class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0)return 1;
        int numBits = (int)log2(num)+1;
        unsigned int mask = (1U<<numBits)-1;
        return  num ^ mask; 

    }
};