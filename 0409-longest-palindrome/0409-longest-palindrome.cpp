class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int arr[52]={0};
        for(int i =0;i<n;++i){
            if(islower(s[i]))arr[s[i]-'a']++;
            else if(isupper(s[i]))arr[s[i]-'A'+26]++;
        }
        int ans =0;
        bool flag = false;
        for(auto x : arr){
            if(x%2==0)ans+=x;
            else {
                flag= true;
                ans+=(x-(x%2));
            }
        }
        return (flag)?ans+1:ans;


    }
};