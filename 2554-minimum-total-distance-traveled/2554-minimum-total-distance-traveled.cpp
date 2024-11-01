class Solution {
public:
        // find the number of robots is repaired by factory within the limit.
        // expand the factory to its limit times
        // ith robot is repaired by left of its j the factory or next factory 
        // take  = abs(pos[i]-robot[i])  + solve(i+1,j+1,robot ,factory);
        // int notTake = solve(i,j+1,robot,factory);
        //return min(take,notTake);
#define ll long long
int m, n;
vector<vector<ll>> dp;

ll solve(int i, int j, std::vector<int>& robots, std::vector<int>& factoryPos) {
    // base case:
    if (i >= m) return 0;
    if (j >= n) return 1e16;
    if (dp[i][j] != -1) return dp[i][j];
    
    ll take = abs(robots[i] - factoryPos[j]) + solve(i + 1, j + 1, robots, factoryPos);
    ll notTake = solve(i, j + 1, robots, factoryPos);
    
    return dp[i][j] = min(take, notTake);
}

long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
    // Sort helps to find the nearest factory for the i-th robot at j-th factory
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    m = robot.size();
    n = factory.size();
    
    // Expand factory positions based on their limits
    vector<int> expandFactory;
    for (auto x : factory) {
        int pos = x[0];
        int limit = x[1];
        while (limit--) expandFactory.push_back(pos);
    }
    
    n = expandFactory.size(); // Update n to reflect the expanded factory size
    dp.resize(m + 1, std::vector<ll>(n + 1, -1));
    
    return solve(0, 0, robot, expandFactory);
}

};
