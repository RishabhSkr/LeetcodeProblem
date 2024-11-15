class Solution {
public:
    bool isValid(int n,vector<int>&quant,int mid){
       int cnt = 0;
       for(auto x : quant){
            cnt+=(x/mid);
            if(x%mid)cnt++;
            if(cnt>n)return 0;
       }
        return cnt<=n;
    }

    int minimizedMaximum(int n, vector<int>& quant) {
        int ans = -1;
        int lo =1 , hi = *max_element(quant.begin(),quant.end());
        
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(isValid(n,quant,mid)){
                ans = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        return ans;
    }
};