class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int min) {
        int unSatify =0,i =0,j =0,curr =0,ans=0;
       while(j<cust.size()){
        if(grumpy[j]==0)ans+=cust[j];
        else curr+=cust[j];
        if(j-i+1>min){
            if(grumpy[i]==1){
                curr-=cust[i];
            }
            i++;
        }
        // cout<<ans<<" "<<curr<<endl;
        unSatify = max(unSatify,curr);
        j++;
       }
       return ans+unSatify;
    }
};