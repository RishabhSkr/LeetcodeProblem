class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) { 
     deque<pair<int, int>> dq; // Store pairs of (skill, index)
        int maxi = -1,max_idx = -1;
        for (int i = 0; i < skills.size(); ++i) {
            dq.push_back({skills[i], i});
            if(maxi<skills[i]){
                maxi = skills[i];
                max_idx = i;
            }
    
        }
        if(k>skills.size())return max_idx;
        int win_streak = 0;
        pair<int, int> curr = dq.front();
        dq.pop_front();

        while (win_streak < k && !dq.empty()) {
            pair<int, int> p2 = dq.front();
            dq.pop_front();

            if (curr.first > p2.first) {
                ++win_streak;
                dq.push_back(p2);
            } else {
                dq.push_back(curr); 
                curr = p2;
                win_streak = 1;
            }

            if (curr.first == maxi) {
                return curr.second;
            }
        }

        return curr.second;
    }
}; // 28063
