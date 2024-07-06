class Solution {
public:
    int passThePillow(int n, int time) {
        int count =1;
        int dirn =1;
        while(time--){
            if(count==n)dirn=-1;
            if(count==1)dirn =1;
            count+=dirn;
        }
        return count;
    }
};