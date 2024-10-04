class Solution {
public:
#define ll long long
    long long dividePlayers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll ans =0;
        int n = nums.size(),i = 0,j =n-1;
        ll sum =-1;
        while(i<j){
            ll curr = nums[i]+nums[j];
            cout<<curr<<" "<<sum<<endl;
            if(sum==-1){
                sum = curr;
                ans+=(nums[i]*nums[j]);
            }else{
                if(sum==curr){
                    ans+=(nums[i]*nums[j]);
                    sum = curr;
                }else return -1;
            }
            i++;
            j--;
        }
        return ans;
    }
};