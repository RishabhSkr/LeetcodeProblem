class Solution {
public:
// https://youtu.be/Dz-WjxVqcmA
long long getCount(int n,long long  left,long long  right){
    long long  cnt = 0;
    while(left<=n){
        cnt +=(min(1LL*n+1,1LL*right)-1LL*left); // hum k liye nikal rhe kitne number chorne padenge +1 kyunki root node 1 to hga
        left*=10;
        right*=10;
    }
    return cnt;
}
    int findKthNumber(int n, int k) {
        // go to level by level decrease k untile k>0
        long long curr = 1;
        k--; // 1 liya already
        while(k>0){
            long long steps = getCount(n,curr,curr+1);
            if(steps<=k){
                curr++;
                k-=steps;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr; 
    }
};