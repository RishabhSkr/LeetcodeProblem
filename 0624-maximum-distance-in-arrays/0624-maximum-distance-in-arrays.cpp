class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n = arr.size();
        int left = arr[0][0],right = arr[0].back();
        int ans = 0;
        for(int i =1;i<n;++i){
            ans = max(ans,max(abs(arr[i].back()-left),abs(right-arr[i][0])));
            right = max(right,arr[i].back());
            left  = min(left,arr[i][0]);
        }
        return ans;
        
    }
};