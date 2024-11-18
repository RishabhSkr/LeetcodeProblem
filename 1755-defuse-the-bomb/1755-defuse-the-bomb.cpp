class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        if(k>0){
            for(int i = 0;i<n;++i){
                int sum = 0;
                int cnt = k;
                for(int j = i+1;cnt--;++j){
                    sum+=(code[j%n]);
                }
                ans[i]= sum;
            }
        }else if(k<0){
             for (int i = 0; i < n; ++i) {
                int sum = 0;
                for (int j = 1; j <= -k; ++j) {
                    int wrapped_index = (i - j + n) % n;  // Wrap backward
                    sum += code[wrapped_index];
                }
                ans[i] = sum;
            }
        }else{
            fill(ans.begin(), ans.end(), 0);
        }
        return ans;
    }
};