class Solution {
public:
int n;
int WIDTH ;// when new shelf starts
vector<vector<int>>dp;
    int solve(int ind,int remWidth,int maxH,vector<vector<int>>& books){
        // base case
            if(ind>=n)return maxH;
            if(dp[ind][remWidth]!=-1)return dp[ind][remWidth];
        // explore
            int bookw = books[ind][0];
            int bookh = books[ind][1];
            int take = INT_MAX;
            if(bookw<=remWidth){
                take=solve(ind+1,remWidth-bookw,max(maxH,bookh),books);
            }
            int notTake = maxH+solve(ind+1,WIDTH-bookw,bookh,books); // when new shel start you again have 4 width  and you have to curr book when you cant put in prev one and maxH will be calculated as prev maxH + currentMax i.e bookh
        return dp[ind][remWidth]=min(take,notTake);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        WIDTH = shelfWidth;
        dp.resize(n+1,vector<int>(shelfWidth+1,-1));
        return solve(0,shelfWidth,0,books);
    }
};