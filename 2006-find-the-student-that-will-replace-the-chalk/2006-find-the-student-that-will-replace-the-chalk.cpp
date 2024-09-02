class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(auto x : chalk)sum+=x;
        int round = k/sum;
        k = k-round*sum;
        for(int i =0;i<n;++i){
            if(k-chalk[i]>=0)k-=chalk[i];
            else return i;
        }
        return -1;
    }
};