class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto str: details){
            string s =str.substr(11,2);
            // cout<<s<<endl;
            int age =stoi(s);
            if(age>60)cnt++;
        }
        return cnt;
    }
};