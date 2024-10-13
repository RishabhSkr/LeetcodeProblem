class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int>range ={0,INT_MAX};
        int k = nums.size();

        vector<int>index(k,0);

        while(true){
            int mini = 1e9,maxi=-1,ind=0;
            for(int i = 0;i<k;++i){
               int curr = nums[i][index[i]];

               if(curr<mini){
                mini = curr;
                ind = i;
               }

               if(curr>maxi){
                maxi = curr;
               }
            }
            
            if(maxi-mini<range[1]-range[0]){
                range[0]=mini;
                range[1]=maxi;
            }

            index[ind]++;

            if(index[ind]==nums[ind].size())break;

            
        }   
        return range;
    }
};