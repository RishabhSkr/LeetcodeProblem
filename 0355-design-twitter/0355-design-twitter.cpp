class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets; // Stores tweets with timestamp
    unordered_map<int, set<int>> followers; // Stores followers of each user
    
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // Local priority queue for every query of newsFeed

        // Add user's own tweets
        for (const auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Add tweets from followed users
        for (const int& followeeId : followers[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                pq.push(tweet);
            }
        }

        // Collect up to 10 most recent tweets
        vector<int> newsFeed;
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            newsFeed.push_back(pq.top().second);
            pq.pop();
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) { // Prevent self-follow
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */