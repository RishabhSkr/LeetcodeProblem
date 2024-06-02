class Solution {
public:
// currentOccupancy: This will track the current number of people in the waiting room.
// maxOccupancy: This will track the maximum number of people in the waiting room at any point in time.
    int minimumChairs(string s) {
        int curr = 0;
        int maxChair = 0;
        for(int i = 0;i<s.size();++i){
            if(s[i]=='E')curr++;
            else curr--;
            maxChair=max(curr,maxChair);
        }
        return maxChair;
    }
};