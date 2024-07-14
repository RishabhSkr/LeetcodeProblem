class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>()); // PUSH IT FIRST OTHERWISE IT GIVE RUNTIME ERROR
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top(); // Map at the top
                st.pop();
                i++;

                // Read the multiplier after ')'
                string multiplier = "";
                while (i < n && isdigit(formula[i])) {
                    multiplier.push_back(formula[i]);
                    i++;
                }

                if(!multiplier.empty()){
                    int multInt = stoi(multiplier);
                    for(auto &it : curr){
                        string ele = it.first;
                        int cnt = it.second;
                        curr[ele]=cnt*multInt;
                    }
                }


                // Merge this map with the map currently at the top of the stack
                for(auto &it : curr){
                    string ele = it.first;
                    int cnt = it.second;
                    st.top()[ele] += cnt;
                }


            } else {
                string currElem = "";
                currElem.push_back(formula[i]); // "He,Mg"      
                i++;
                if (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currElem.push_back(formula[i]);
                    i++;
                }

                // Read the count of the current element
                string currCnt = "";
                while (i < n && isdigit(formula[i])) {
                    currCnt.push_back(formula[i]);
                    i++;
                }

                int currCntInt = (!currCnt.empty()) ? stoi(currCnt) : 1;
                st.top()[currElem] += currCntInt;
            }
        }

        // The stack will only have one element in the form of unordered_map with counts
        map<string,int>sortedMap(st.top().begin(),st.top().end());
        string res = "";
        for(auto &it:sortedMap){
            string ele = it.first;
            res+=ele;  
            int cnt = it.second;
            if(cnt>1)res+=to_string(cnt);
        }
        return res;
    }
};