class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n= arr.size();
        int left = 0 ,right = n-1;
        while(left+1 < n && arr[left]<= arr[left+1] )left++;

        if(left==n)return 0;
        while(right >left && arr[right]>=arr[right-1])right--;

        int ans = min(n-left-1,right);
        int i =0,j = right;
        while(i<=left && j<n){
            if(arr[j]>=arr[i]){
                ans = min(j-i-1,ans);
                i++;
            }else ++j;
        }
        return ans==-1? 0 : ans;
    }
};