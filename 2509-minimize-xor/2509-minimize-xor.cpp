class Solution {
public:
    /*
        1. count set bits in num2 put same as in x
        2. now 32 bits number max can
        3. start iterating 32 bits and as minimize xXornum1 we need unset the leftmost bit 0 and set
        4. the rightmost bit 1 where zero 
        5. ans is generated unique
        6. return the ans.
        ---------------------------------------------------
        Key poits to solve this problem:

If the set bit in both number are equal we can come up with a minimal value which is 0, hence the num1 itself become answer.
if the set bit in num1 is greater than num2(diff > 0) then we need to unset diff number of set bits from LSB side from num1. (use Eq: n & (n - 1) for this task)
at last if the diff < 0 then unset the diff number of bits from LSB side from num1 (use Eq: n | (n + 1) for this task)
Intuition behind each key points:

if set bits are equal then we will make number x such that all the set bit of this x align with the position of set bits in num1, we do this because when we XOR same bits result to 0 (1 ^ 1 = 0, 0 ^ 0 = 0)

Here also we are trying the match bits from MSB side so that the xor will make result as small possible, but we have extra bits in num1 and that extra bit will be the one which will be the result of num1 and x.
take example: nums1 = 1 0 0 0 0 1 0 0 0 1 0 1 1 1 and nums2 = 111

to get the smallest result possible our x should have bits such that when we XOR the nums1 MSB bits should become zero so our x looks like
x = 1 0 0 0 0 1 0 0 0 1 0 0 0 0

now when we xor nums1 and x
1 0 0 0 0 1 0 0 0 1 0 1 1 1
1 0 0 0 0 1 0 0 0 1 0 0 0 0 ^
0 0 0 0 0 0 0 0 0 0 0 1 1 1

which is smallest
hence dosn't your problem reduces to just making x from nums1 and we do it by removing the number of diff set bits from nums1.
and we use the quation given above.

The same idea we have when diff < 0, there we just want to set the unset bit to 1 and the equation helps us.
You need to take out pen and paper and try out some example otherwise reading this holistic article will not able to teach you anything sorry.
    */
    int minimizeXor(int num1, int num2) {
        int cntBits=0;
        for(int i= 31 ; i>=0;--i){
            if(num2&(1<<i))cntBits++;
        }
        int ans =0;
        // set MSB bits of num1 to ans 
        for(int i=31;i>=0 && cntBits>0;--i){
            if(num1&(1<<i)){ // check bit to 1 or 0
                cntBits--;
                ans|=(1<<i); // set bit to 1
            }
        }
        // right most bit which are left cntBits>0
        for(int i = 0 ; i<32 && cntBits>0;++i){
              if((ans&(1<<i))==0){ // check bit to 1 or 0
                cntBits--;
                ans|=(1<<i); // set bit to 1
            }
        }
        return ans;
    }
};