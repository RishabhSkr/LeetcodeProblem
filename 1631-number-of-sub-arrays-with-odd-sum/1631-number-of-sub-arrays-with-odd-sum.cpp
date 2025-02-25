class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>pref(n,0);
        pref[0]=arr[0];
        for(int i=1;i<n;++i){
            pref[i]=pref[i-1]+arr[i];
        }
        int mod  = 1e9+7;
        int cnt = 0;
        int odd = 0;
        int even = 1; // initial = 0

        for(int i =0;i<n;++i){
            if(pref[i]%2==0){ // even+odd
                cnt= (cnt+odd)%mod;
                even++;
            }else{
                cnt= (cnt+even)%mod; // odd+even
                odd++;
            }
        }
        return cnt;
    }
};