class Solution {
public:
    int findTheLongestSubstring(string s) {
       vector<int>mp(32,-2); // 5 vowels and only 2pow 32 combination are present so each combination respresent represent set vowels present or not. 0 all vowels are in even state 1 means odd
       int maxi = 0;
       int mask = 0;
       mp[0]=-1;
       for(int i =0;i<s.size();++i){
        char ch = s[i];
        if(ch=='a')mask^=1;
        else if(ch=='e')mask^=2;
        else if(ch=='i')mask^=4;
        else if(ch=='o')mask^=8;
        else if(ch=='u')mask^=16;
        int prev = mp[mask];
        if(prev==-2){
            mp[mask]=i;
        }else{
            maxi = max(maxi,i-prev);
        }
       }
        return maxi;
    }
};