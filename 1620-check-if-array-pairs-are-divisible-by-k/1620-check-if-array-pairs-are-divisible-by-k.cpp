class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>counts(k,0);// [0,k-1] remainder freq store
        int ans =0;
        for(auto num : arr){
            int rem = (num%k+k)%k; //handling -ve add +k then take mod
            counts[rem]++;    
        }
        for(int i =1;i<k;++i){
            if(counts[i]!=counts[k-i])return false;

        }
        return counts[0]%2==0;
    }
};