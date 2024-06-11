class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n =arr1.size();
        map<int,int>mp;
        for(int i =0;i<n;++i){
            mp[arr1[i]]++;
        }
        int pos =0,n2 =arr2.size();
        vector<int>ans;
        while(pos<n2){
            if(mp.count(arr2[pos])>0){
                while(mp[arr2[pos]]>0){
                    ans.push_back(arr2[pos]);
                    mp[arr2[pos]]--;
                }
            }
            pos++;
        }
        for(auto x : mp){
            if(x.second>0){
                while(x.second-->0)ans.push_back(x.first);
            }
        }
        return ans;
    }
};