class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size(),i = 0,j=n-1;
        int lsum = 0,maxSum=0;
        int cnt = 0;
        while(i<k)lsum+=cards[i++];
        maxSum = lsum;
        int rsum = 0;
        k--;
        while(k>=0){
            lsum-=cards[k--];
            rsum+=cards[j--];
            maxSum = max(rsum+lsum,maxSum);
        }
        return maxSum;
    }
};