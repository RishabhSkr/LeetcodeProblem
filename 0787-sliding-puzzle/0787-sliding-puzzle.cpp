class Solution {
public:
    // Manhattan distance calculation helper
    int getManhattanDistance(vector<vector<int>>& board) {
        int distance = 0;
        // Target positions for each number
        unordered_map<int, pair<int,int>> target = {
            {1, {0,0}}, {2, {0,1}}, {3, {0,2}},
            {4, {1,0}}, {5, {1,1}}, {0, {1,2}}
        };
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] != 0) {  // Skip empty tile
                    auto [ti, tj] = target[board[i][j]];
                    distance += abs(ti - i) + abs(tj - j);
                }
            }
        }
        return distance;
    }
    
    // Convert board to string for visited state tracking
    string boardToString(vector<vector<int>>& board) {
        string key = "";
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                key += to_string(board[i][j]) + ",";
        return key;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        // Direction arrays for 4-directional movement
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Priority queue entries: {f_score, steps, board_state}
        // where f_score = steps + manhattan_distance (A* heuristic)
        priority_queue<pair<int,pair<int,vector<vector<int>>>>,
                      vector<pair<int,pair<int,vector<vector<int>>>>>,
                      greater<>> pq;
        
        // Track visited states
        unordered_set<string> visited;
        
        // Find initial position of 0
        int zi = 0, zj = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                if(board[i][j] == 0) {
                    zi = i;
                    zj = j;
                }
        
        // Initialize priority queue
        int initial_h = getManhattanDistance(board);
        pq.push({initial_h, {0, board}});
        visited.insert(boardToString(board));
        
        while(!pq.empty()) {
            auto [f_score, state] = pq.top();
            auto [steps, curr_board] = state;
            pq.pop();
            
            // Check if current state is goal state
            if(getManhattanDistance(curr_board) == 0)
                return steps;
            
            // Find current position of 0
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 3; j++)
                    if(curr_board[i][j] == 0) {
                        zi = i;
                        zj = j;
                    }
            
            // Try all possible moves
            for(auto [di, dj] : dirs) {
                int ni = zi + di;
                int nj = zj + dj;
                
                if(ni >= 0 && ni < 2 && nj >= 0 && nj < 3) {
                    vector<vector<int>> new_board = curr_board;
                    swap(new_board[zi][zj], new_board[ni][nj]);
                    
                    string new_state = boardToString(new_board);
                    if(!visited.count(new_state)) {
                        visited.insert(new_state);
                        int h = getManhattanDistance(new_board);
                        pq.push({steps + 1 + h, {steps + 1, new_board}});
                    }
                }
            }
        }
        
        return -1;  // No solution found
    }
};