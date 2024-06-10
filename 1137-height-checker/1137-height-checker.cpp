class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>temp(begin(h),end(h));
        sort(begin(temp),end(temp));
        int cnt =0;
        for(int i =0;i<temp.size();++i){
            if(temp[i]!=h[i])cnt++;
        }
        return cnt;
    }
};