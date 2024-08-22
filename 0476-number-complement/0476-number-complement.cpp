class Solution {
public:
    int findComplement(int num) {
        int numBits =(int)log2(num)+1; // 5 = 101 = 3  mask==001
        // for(int i =0;i<numBits;++i){
        //     num=num^(1<<i); // yaha 1 ko 1-1 bit flip kr rhe..1<<i(0 to n-1th bit) flip
        // }
        // return num;

        // 2nd Apporach using concept create a bitmask equal to number of bits and take xor with num
            // how to create a bitmask n bits = num bits
                // concept = 101 -> 3 bits = 2pow3 = 8-1 = 0111; mask = (pow(2,numBits)-1) or (1<<numBits)-1
          
            unsigned int mask = (1U<<numBits)-1;
            return  num ^ mask; 
        // 3rd Approach
        
          
    }
};