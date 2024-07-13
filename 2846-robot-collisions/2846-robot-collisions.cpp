class Solution {
public:


vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    // 1->R and 0 ->L


    vector<int> roboIdx;

    for (int i = 0; i < n; ++i) {  
        roboIdx.push_back(i);
    }

    sort(roboIdx.begin(), roboIdx.end(), [&](int &a, int &b) { // a>b
        return positions[a] < positions[b];
    });

    stack<int> st;
    for (int i : roboIdx) {
      
        if (directions[i] == 'L') {
            while (!st.empty() &&  healths[i]>0) {
               
                //check collision from stack top element
                 int topIdx = st.top();
                    st.pop();
                 // if top survives
                if ( healths[topIdx] > healths[i]) {
                     healths[topIdx]-=1;
                     healths[i] = 0;
                    st.push(topIdx);
                    
                }// if curr robo survives 
                else if (healths[topIdx] <  healths[i]) {
                    healths[topIdx]=0;
                    healths[i]--;
                }else{
                   healths[topIdx] = 0;
                   healths[i] = 0;
                }
            }
        } else {
            st.push(i);
        }
    }
    

    vector<int> ans;
    for(int i =0;i<n;++i){
        if(healths[i]>0)ans.push_back(healths[i]);
    }
    return ans;
}
};