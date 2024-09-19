class Solution {
public:
    vector<int> solve(string s){
        vector<int>res;
        for(int i =0;i<s.size();++i){
            if(s[i]=='-' || s[i]=='+'||s[i]=='*'){

                vector<int>leftRes = solve(s.substr(0,i));
                vector<int>rightRes = solve(s.substr(i+1));

                for(int num1 : leftRes){
                    for(int num2 : rightRes){
                        if(s[i]=='+'){
                            res.emplace_back(num1+num2);
                        }else if(s[i]=='-'){
                            res.emplace_back(num1-num2);
                        }else if(s[i]=='*'){
                            res.emplace_back(num1*num2);
                        }
                    }

                }
            }
        }
        if(res.empty())res.emplace_back(stoi(s));
        return res;
    }
    vector<int> diffWaysToCompute(string exp) {
        return solve(exp);
    }
};