class Solution {
public:
/*
 Use x=y⊕z⟺x⊕y=y⊕z⊕y=z
 der[i] = ori[i]^ori[i+1]
 ori[i+1]= der[i]^ori[i](0,1)
*/
    bool doesValidArrayExist(vector<int>& der) {
        vector<int>ori={0};
        int n =der.size();
        for(int i =0;i<n;++i){
            ori.push_back(der[i]^ori[i]);
        }
        if(ori[n-1]^ori[0]==der[n-1])return true;
        ori={1};
        for(int i =0;i<n;++i){
            ori.push_back(der[i]^ori[i]);
        }
         if(ori[n-1]^ori[0]==der[n-1])return true;
         return false;
    }
};