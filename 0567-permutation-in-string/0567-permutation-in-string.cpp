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
        
        sort(s1.begin(),s1.end());

        for(int ind = 0;ind<n2;++ind){
           string str = s2.substr(ind,n1);
           sort(str.begin(),str.end());
            if(s1==str)return true;    
        }
       return false;
    }
};