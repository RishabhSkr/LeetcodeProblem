class Solution {
public:
#define ll long long
     int binSearch(const vector<ll>& prefixSum, ll q, int maxi){
        int lo = 1, hi = maxi;
        int answer = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(prefixSum[mid] > q){
                answer = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return answer;
    }
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // maxi ,nums,
        //  count maxi gcd upto NUM can have
        int maxi = *max_element(nums.begin(),nums.end());

         // Frequency array for counting occurrences of each number in `nums`
        vector<ll> cnt(maxi + 1, 0);
        for (auto x : nums) cnt[x]++;

        // cnt multiple which are divisble by each gcd
        vector<ll> gcdFreq(maxi+1,0);
        for(int gcd=1;gcd<=maxi;++gcd){
            long long multiple =0;
             // Count how many pairs have GCD equal to 'i'.
            for(int j = gcd;j<=maxi;j+=gcd){
                multiple += cnt[j];
            }
             // Calculate total pairs for current GCD. choosing nC2 pairs
             gcdFreq[gcd]=(1LL * (multiple)*(multiple-1))/2;

        }

        for(int gcd=maxi;gcd>=1;gcd--){
              // Subtract pairs that would have a larger GCD duplicate count in curr.
            for(int nxtGcd = 2*gcd ;nxtGcd<=maxi;nxtGcd+=gcd){
                gcdFreq[gcd]-=gcdFreq[nxtGcd];
            }
        }
        // now we successfully created the gcd occurrence in term of freq
        // Create a prefix sum array to store cumulative GCD counts.
        vector<ll> prefixSum(maxi+1,0);
        for(int gcd = 1;gcd<=maxi;gcd++){
            prefixSum[gcd]=prefixSum[gcd-1]+gcdFreq[gcd];
        }

        // for each query 1e5*1e5 search space will take Now optimise it using BinSearch
        vector<int>res;
        for(auto &q : queries){
            res.push_back(binSearch(prefixSum,q,maxi));
        }
        return res;
    }
};