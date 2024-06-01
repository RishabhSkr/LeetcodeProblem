class Solution {
public:
// Idle time is the time that was needed in the cycle because no task was available. It is the remaining cycle length in our algorithm. Idle time should be only added if the priority queue is empty (i.e all tasks are completed)
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        for(auto x : tasks)mp[x]++;
        priority_queue<int>pq;
        for(auto x : mp){
            pq.push(x.second);
            // cout<<x.second<<endl;
        }
        int time =0;
        while(!pq.empty()){
            int freq =0;
            vector<int>task;
            for(int i =1;i<=n+1;++i){
                if(!pq.empty()){
                    freq =pq.top();
                    pq.pop();
                    freq--;
                    task.push_back(freq);
                }
            }
            for(auto freq : task){
                if(freq>0)pq.push(freq);
            }
        if(pq.empty())time+=task.size(); // all task completed and no other in pq.remaining task <n in array whose freq becomes zero
            else time+=n+1;//(cycle) if task can be completed the we need n+1  cycle everytime 
                                        // AB_|AB_|AB_|B    n=2
                                        // n+1|n+1|n+1|temp.size()
        }
        return time;
    }
//  total time= (cycle length)*(maximum frequency-1) + number maximum frequency tasks that are left  
// i.e total time=(n+1)*(max_freq-1)+count_maxfreq_task
};