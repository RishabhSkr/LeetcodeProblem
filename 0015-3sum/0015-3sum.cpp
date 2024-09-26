class Solution {
public:
        //brute force O(n3) S.C(2*(number of unqique trplets)==(N))
        // set<vector<int>>st;
        // for(int i =0;i< n;++i){
        //     for(int j =i+1;j<n-1;++j){
        //       for(int k = j+1 ;k<n;++k){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int>temp = {nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // set<vector<int>>st;
        // for(int i =0;i< n;++i){
        //     unordered_map<int,int>mp;
        //     for(int j =i+1;j<n;++j){
        //         int k = -1*(nums[i]+nums[j]);
        //         if(mp.count(k)){
        //             vector<int>temp = {nums[i],nums[j],k};
        //             st.insert(temp);
        //         }
        //         mp[nums[j]]=1;// store the number for iterators j,k
        //     }
        // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // T.C O(n^2) S.C (O(1))
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(n<3)return {};
        for(int i =0;i<n;++i){
            if(i!=0 && nums[i-1]==nums[i])continue; // remove duplicates for i also 
            int j =i+1;
            int k= n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    // skip the duplicates for j and k also
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(k>j && nums[k]==nums[k+1])k--; // k+1 and k should be equal
                }
                
            }
        }
        return res;
    }
};