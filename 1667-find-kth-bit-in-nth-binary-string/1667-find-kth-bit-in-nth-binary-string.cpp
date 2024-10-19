class Solution {
public:
// https://leetcode.com/problems/k-th-symbol-in-grammar/submissions/1262841616/

    char findKthBit(int n, int k) {
        if(n==1)return '0'; // edge case

        int len = (1<<n)-1; // str len will be pow(2,n-1)
        
        // if k is less than n/2 , si = (si-1) ans of kth bit
        if(k<ceil(len/2.0))return findKthBit(n-1,k);
        // if k is exactly in the middle,return 1
        else if(k==ceil(len/2.0))return '1';
        else{
            // you don't have to genrate all string , first reverse is second half,return n- (k-1)th in first half because pos will be same and just the reverse the obtain char it
            // kth = n-(k-1)th
            char ch =findKthBit(n-1,len-(k-1));
            if(ch=='0')return '1';
            else return '0';
        } 
    }
};

