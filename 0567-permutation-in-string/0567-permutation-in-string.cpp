class Solution {
public:

    // void solve(int ind,string &s1,string &s2){
    //     if(ind==n1){
    //         if(s2.find(s1)!= string::npos)ans =true;
    //         return ;
    //     }
    //     for(int i = ind;i<n1;++i){
    //         swap(s1[i],s1[ind]);
    //         solve(ind+1,s1,s2);
    //         swap(s1[i],s1[ind]);
    //         if(ans)return; // early return alredy we find permutation
    //     }
        
    // }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1>n2)return false;
        // approach Optimal:sliding window
        int i =0,j = 0;
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        for(auto x : s1)mp1[x-'a']++;
        while(j<n2){
            mp2[s2[j]-'a']++;
            while(j-i+1>n1){
                mp2[s2[i]-'a']--;
                i++;
            }
            if(j-i+1==n1 && mp1==mp2)return true;
            j++;
        }
       return false;
    }
};