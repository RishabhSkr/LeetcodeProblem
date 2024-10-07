class Solution {
public:
    int minLength(string s) {
        // stack<char>st;
        // int cnt  = s.length();
        // for(auto &ch : s){
        //     if (!st.empty() && ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D'))){
        //         st.pop();
        //         cnt-=2;
        //     }else{
        //         st.push(ch);
        //     }
        // }
        // brute force 
        // ab and cd ko delete krte jao O(n2)
        while(s.find("AB")!=-1 || s.find("CD")!=-1){
            
            if(s.find("AB")!=-1){
                s.erase(s.find("AB"),2);
            }else if(s.find("CD")!=-1){
                s.erase(s.find("CD"),2);
            }
        }
        return s.length();
    }
    
};
