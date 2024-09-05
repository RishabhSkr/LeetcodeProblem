class Solution {
public:
    // Clockwise rotation:
    // dx, dy = dy,-dx
    // Counterclockwise rotation:
    // dx, dy = -dy,dx
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        int n = commands.size();
        // store obst
        unordered_set<string>st;
        for(auto it : obs){
            int x =it[0];
            int y = it[1];

            string s = to_string(x)+"_"+to_string(y);
            st.insert(s);
        }
        // intials
        int x = 0,y =0;
        pair<int,int>dir={0,1};// North 
        
        int maxi = 0;
        for(auto it : commands){
            if(it==-2){ // turn 90 left
                dir = {-1*dir.second,dir.first};
            }else if(it==-1){
                dir = {dir.second,-1*dir.first}; // turn right
            }else{
                for(int i =1;i<=it;++i){
                    
                    int newx = x+dir.first;
                    int newy = y+dir.second;

                    string nextStep = to_string(newx)+"_"+to_string(newy);
                    if(st.find(nextStep)!=st.end()){
                        break;
                    }
                    x = newx;
                    y = newy;
                }
            }
            maxi = max(maxi,(x*x+y*y));
        }
        return maxi;

    }
};