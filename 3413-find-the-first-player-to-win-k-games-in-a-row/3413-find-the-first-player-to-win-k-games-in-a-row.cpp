class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) { 
      deque<pair<int,int>>dq;
        int maxi = skills[0],maxIdx =0,n = skills.size(),cnt=0;
        for(int i =1;i<n;++i){
            if(maxi<skills[i]){
                maxi=skills[i];
                maxIdx =i;
                cnt=0;
            }
            if(++cnt>=k)break;
        }
        return maxIdx;
    }
}; 
