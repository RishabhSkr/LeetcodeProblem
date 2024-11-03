class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.empty() || goal.empty())return false;
        if(s.size()!=goal.size())return false;
        string str =s+s;
        return str.find(goal)!=string ::npos;
        
    }
};