class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = arr[0];
        int profit  =-1;
        for(int i = 0;i<arr.size();++i){
            profit= max(arr[i]-mini,profit);
            mini  = min(mini,arr[i]);
        }
        if(profit ==-1)return 0;
        return profit;
    }
};