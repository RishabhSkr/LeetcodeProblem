class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int>ans;
        for(auto num  :  nums){
            if(num==2){
                ans.push_back(-1);
                continue;
            }

            int no = num;
            // find the first 0 from right

            for(int i = 0;1<31;++i){
                if(no&(1<<i))continue; // means set bit h

                // first zero  mila
                int b= i-1;
                int maskb = (1<<b);// usse ek kam wali bit ko set krdo
                int val = (no^maskb);// yeh min number dega
                ans.push_back(val);
                break;
            }
        }

        return ans;
    }
};