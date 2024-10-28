class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Create a set to store all unique numbers from the input array
        set<int>st;
        for(auto x : nums){
            st.insert(x);
        }
        int longest=0;
        for(auto x : nums){
                int currStreak = 0;
                long long currNumber = x;

                 // Continue the streak as long as we can find the next square in the set
                while(st.find((int)currNumber)!=st.end()){
                    currStreak++;
                    // Break if the next square would be larger than 10^5 (problem
                // constraint)
                    if(currNumber*currNumber>1e5)break;
                    currNumber*=currNumber;
                }
                // update the longest Streak to currStreak 
                longest = max(currStreak,longest);
        }
        return longest<2? -1 : longest;
    }
};