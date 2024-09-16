class Solution {
public:
    int findMinDifference(vector<string>& arr) {
        int n = arr.size();
        vector<int>minArr;
        for(auto x : arr){
            int hr= stoi(x.substr(0,2));
            int min = stoi(x.substr(3,2));
            if(hr==0)hr = 24;
            minArr.push_back(hr*60+min);

        }
        sort(begin(minArr),end(minArr));
        int mini=INT_MAX;
        int ans = 0;
        for(int i =1;i<n;++i){
             mini =min(mini,abs(minArr[i]-minArr[i-1]));
        }
        // check for last and first time since time is circular
        int last = 1440 - (minArr[n-1]-minArr[0]);
        return min(mini,last);
    }
};