class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
     // sentence ko equal banana h to simple ek seq me compare krne hone either sentence should be equal from left or right side bich se hga equal to left or right me eual nhi kr skte add krk
     // koi aisa ds choose jisma front and back se compare krte jaaye agr koi bhi empty ho gya return true else false
     deque<string>dq1,dq2;
        string str = "";
        for(auto &ch : s1){
            if(ch!=' ')str+=to_string(ch);
            else{
                dq1.push_back(str);
                str="";
            }
        }
        dq1.push_back(str);

        str="";
        for(auto &ch : s2){
            if(ch!=' ')str+=to_string(ch);
            else{
                dq2.push_back(str);
                str="";
            }
        }
        dq2.push_back(str);
      
        while(!dq1.empty() &&  !dq2.empty() && dq1.front()==dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }
        while(!dq1.empty() &&  !dq2.empty() && dq1.back()==dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }
        
        return dq1.empty() || dq2.empty();
    }
};