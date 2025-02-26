class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i =0;i<arr.size();++i){
            mp[arr[i]]=i;
        }
        for(int i =0;i<arr.size();++i){
            if(mp.find(2*arr[i])!=mp.end() && i!=mp[arr[i]*2]){
                return true;
            }
        }
        return false;
    }
};