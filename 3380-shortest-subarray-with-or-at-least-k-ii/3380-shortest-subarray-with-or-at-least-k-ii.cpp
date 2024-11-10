class Solution {
public:
    int cntSetBits(int &k){
        int reqBits = 0;
      
        return reqBits;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        // plan-> sliding window + frq of bits
        // iterate over arrr and cnt the the no bits till jth.
        // if(we get enough bits as in k or greater try move ith to decrease the subarray)
        // store the min len as an ans  
        // return ans;

       
        int reqBits = cntSetBits(k);
        
        int i =0,j = 0;
        int n = nums.size();
        int ans = 1e9;

        unordered_map<int,int>mp;
        int currOr = 0;
        while(j<n){
            currOr|=nums[j];

            for(int bit = 31 ;bit>=0;bit--){
                if(nums[j]&(1<<bit))mp[bit]++;
            }

            while( i<=j &&  currOr >=k){
                    ans = min(ans,j-i+1);

                    int newOr = 0;

                     for(int bit = 31 ;bit>=0;bit--){
                        if(nums[i] & (1<<bit))mp[bit]--;

                        if(mp[bit]>0){
                            newOr|=(1<<bit);
                        }
                    }
                    currOr = newOr;
                    i++;
            }
            j++;
        }
        return ans==1e9? -1 : ans;
    }
};