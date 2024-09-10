class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,vector<int>&cuts){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini = INT_MAX;
    for(int ind = i;ind<=j;++ind){
        int cost = abs(cuts[j+1]-cuts[i-1])+solve(i,ind-1,cuts)+solve(ind+1,j,cuts);
        mini = min(cost,mini);
    }
    return dp[i][j]=mini;

}
    int minCost(int n, vector<int>& cuts) {
        int size =cuts.size();
        vector<int>arr(size+1,0);
        for(int i =1;i<=size;++i){
            arr[i]=cuts[i-1];
            cout<<arr[i]<<endl;
        }
        arr.push_back(n);
        dp.resize(size+1,vector<int>(size+1,-1));
        sort(arr.begin(),arr.end());
        return solve(1,arr.size()-2,arr);
    }
};