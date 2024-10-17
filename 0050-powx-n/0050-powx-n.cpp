class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int powN = abs(n);
        while(powN>0){
            if(powN&1){
                res=res*x;
            }
            x*=x;
            powN>>=1;
        }
        if(n<0)return (double)1/res;
        return res;
    }
};