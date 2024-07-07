class Solution {
public:
    int numWaterBottles(int n, int b) {
        int ans= n;
            while(n>=b){
                int rem = n%b;
                ans+=n/b;
                n =n/b+rem; 
            }
        return ans;
    }
};