class Solution {
public:
    int setBits(int num){
        int cnt = 0;
        for(int i =31 ;i>=0;--i){
            if(num & (1<<i))cnt++;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        // moving left to right to shift the max element to right 
        // second pass moving right to left to move the min element to left as possbile
        for(int i =0;i+1<n;++i){
            if(arr[i]<=arr[i+1])continue;
            else {
                int cnt = setBits(arr[i]);
                int cnt1= setBits(arr[i+1]);
                if(cnt==cnt1){
                    swap(arr[i],arr[i+1]);
                }
                else return false;
            }
           
        }
        for(int i = n-1 ; i>=1;i--){
            if(arr[i]>=arr[i-1])continue;
            else {
                int cnt = setBits(arr[i]);
                int cnt1= setBits(arr[i-1]);
                if(cnt==cnt1)
                    swap(arr[i],arr[i-1]);
                else return false;
            }
        }

        return true;
    }
};