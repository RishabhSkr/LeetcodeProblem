vector<int> getNSL(int n , vector<int>&arr){
    vector<int>res(n);
    stack<int>st;
    for(int i = 0;i<n;++i){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        res[i]  = (st.empty())?-1: st.top();
        st.push(i);
    }
    return res;
}
vector<int> getNSR(int n , vector<int>&arr){
    vector<int>res(n);
    stack<int>st;
    for(int i = n-1;i>=0;--i){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        res[i]  = (st.empty())?n: st.top();
        st.push(i);
    }
    return res;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>NSL= getNSL(n,heights);
        vector<int>NSR= getNSR(n,heights);
        int ans = INT_MIN;
        for(int i = 0;i<n;++i){
            int left = NSL[i];
            int right = NSR[i];
            int width= right-left-1;
            ans = max(heights[i]*width,ans);
        }
        return ans;
    }
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MIN;
        vector<int>arr(n,0);
        for(int i = 0; i<m;++i){
            for(int j = 0;j<n;++j){
                if(matrix[i][j]=='0')arr[j]=0;
                else arr[j]++;
            }
            // histogram is created .. apply the  larget area in histogram
            res = max(res,largestRectangleArea(arr));
           
        }
      return res;
    }
};