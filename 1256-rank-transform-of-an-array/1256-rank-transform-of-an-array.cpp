class Solution {
public:
   
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();
        if(n<1)return {};
        vector<pair<int,int>>temp(n);
        for(int i =0;i<n;++i){
            temp[i]={arr[i],i};
        }
        sort(temp.begin(),temp.end()); // sort acc to ele
        int cnt = 1;
        arr[temp[0].second]=cnt;
        for(int i = 1;i<n;++i){
            if( temp[i].first!=temp[i-1].first) arr[(temp[i].second)]=++cnt;
            else  arr[(temp[i].second)]=cnt;
        }
        return arr;
    }
};