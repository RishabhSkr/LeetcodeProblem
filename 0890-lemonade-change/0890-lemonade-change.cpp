class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0,ten = 0,twenty = 0;
        for(auto x : bills){
            if(x==5)five++;
            else if(x==10){
                ten++;
                if(five>=1)
                    five--;
                else return false;
            }
            else {
                twenty++;
                if(ten>=1 && five>=1)ten--,five--;
                else if(five>=3)five-=3;
                else return false;
                
                
            }
        }
        return true;
    }
};