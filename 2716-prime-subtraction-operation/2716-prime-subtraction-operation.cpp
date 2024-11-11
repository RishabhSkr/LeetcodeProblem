class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        int n = nums.size();
        bool is_prime[1001];
        memset(is_prime,true,sizeof(is_prime));

        is_prime[0] = is_prime[1] = false;

        // Generate prime numbers up to 1000 (loglogn)
        for (int i = 2; i * i <= 1000; i++) {
            if (is_prime[i]) {
                for (int j = 2* i; j <= 1000; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        for (int i = n-2; i >=0; i--) {
            
            if (nums[i+1] <= nums[i]) {
                int diff = abs(nums[i+1]-nums[i])+1;// req prime should be greater than the diff+1
                int prime = -1;
                for (int j = max(2,diff); j<=1000; j++) {
                   if(is_prime[j]){
                    prime =j;
                    break;
                   }
                }
                // cout<<prime<<" "<<nums[i]<<" "<<i<<endl;
                if (prime != -1 && prime < nums[i]) {
                    nums[i] -= prime;
                }else return false;
            }
        }
        // for(auto x : nums)cout<<x<<" ";

        return true;
    }
};