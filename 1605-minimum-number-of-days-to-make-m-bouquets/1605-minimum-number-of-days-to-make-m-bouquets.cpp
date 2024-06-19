class Solution {
public:
bool isPossible(int days,vector<int>arr,int m,int n,int k){
    int M =0,cnt=0;
    for(int i =0;i<n;++i){
        if(arr[i]<=days){
            cnt++;
        }else cnt=0;
            if(cnt==k){
                M++;
                cnt=0;
            }
          
    }
    return M>=m; // atleast m bouquet is can be needed so try to minimize
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(),ans =0;
        if((long)m*k>n)return -1;
        auto maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int s =1, e = maxi;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(mid,bloomDay,m,n,k)){
                ans =mid;
                e= mid-1; // decresing with maximum to lowest that satisfy m buquets
            }else s=mid+1;
        }
        return ans;
    }
};