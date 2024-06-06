class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize)return false;
        priority_queue<int>pq; // using max heap as min-heap
        unordered_map<int,int>mp;
        for(auto x: hand)mp[x]++,pq.push(-x);
       
        while(!pq.empty()){
           int ele =-pq.top();
           pq.pop();
           if(mp[ele]==0)continue;
            int remain = groupSize-1;
            mp[ele]--;
            //check for consecutive elements in map
            while(remain){
                if(mp[ele+1])remain--,mp[ele+1]--,ele=ele+1;
                else return false;
            }
           
        }
        return true;
    }
};