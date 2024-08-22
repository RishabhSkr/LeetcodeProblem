class Solution {
public:
    int findComplement(int num) {
        int numBits =(int)log2(num)+1; // 5 = 101 = 3  mask==001
        for(int i =0;i<numBits;++i){
            num=num^(1<<i); // yaha 1 ko 1-1 bit flip kr rhe..1<<i(0 to n-1th bit) flip
        }
        return num;
        
    }
};