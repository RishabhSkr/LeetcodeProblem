class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& stu) {
        sort(seats.begin(),seats.end());
        sort(stu.begin(),stu.end());
        int ans =0;
        for(int i =0;i<stu.size();++i){
            ans+=abs(stu[i]-seats[i]);
        }
        return ans;
    }
};