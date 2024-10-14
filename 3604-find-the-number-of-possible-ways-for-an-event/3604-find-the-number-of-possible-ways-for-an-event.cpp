class Solution {
public:
#define int long long
int mod =1e9+7;
int fact[1001];

int powm(int x, int n){
    int result = 1;
    x %= mod;
    while(n > 0){
        if(n & 1){
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return result;
}

    // Learn inverse mode
    int mod_div(int p, int q) { return p % mod * powm(q, mod - 2) % mod; }

    int nCr(int n,int r){
        if(r>n)return 0;
        return mod_div(fact[n],fact[n-r]*fact[r])%mod;
    }

    int numberOfWays(int n, int x, int y) {
        
        // precompute factorinal
        fact[0]=1;
        for(int i =1;i<=1000;++i){
            fact[i]= (fact[i-1]*i)%mod;
        }

        // calculate dp of n * x
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));
        //base case
        dp[0][0]=1;
        dp[1][0]=0;
        dp[0][1]=0;
        for(int i=1;i<=n;++i){
            for(int j =1;j<=x;++j){
              dp[i][j] = ( (j * dp[i-1][j]) % mod + dp[i-1][j-1] ) % mod;
            }
        }

        int ans =0;
        for(int i =1;i<=x;++i){
            ans=(ans + (nCr(x,i)*powm(y,i)%mod*dp[n][i]%mod*fact[i]%mod)%mod)%mod;
        }
        return ans;

    }
#undef int
};