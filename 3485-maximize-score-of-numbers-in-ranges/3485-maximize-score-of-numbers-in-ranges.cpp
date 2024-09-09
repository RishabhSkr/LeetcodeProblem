class Solution {
public:
#define ll long long 
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(),start.end());
        ll low = 0,hi = start.back()+d;
        ll ans = 0;
        while(low<=hi){
            ll mid = low + (hi-low)/2;
            // Lambda to check the condition
            auto check = [&](ll mid) -> bool {
                ll prev = start[0];
                for (int i = 1; i < n; ++i) {
                    ll next = max(prev + mid, (ll)start[i]);
                    if (next > start[i] + d) return false;
                    prev = next;
                }
                return true;
            };

            if(check(mid)){
                ans = mid ;
                low = mid+1;
            }else hi = mid-1;
        }
        return ans;
    }
};