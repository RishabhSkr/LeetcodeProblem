class Solution {
public:
bool isPossible(int dist,vector<int>arr,int m,int n){
    int lastPos=arr[0];
    m--; // one ball always can be placed at first pos.
    for(int i =1;i<n;++i){
        if((arr[i]-lastPos)>=dist){
            m--;
            lastPos = arr[i]; // check after placing the ball at ith store the lastLocation of ball so that you can take next dist diff from last point
        }
        if (m == 0) return true; // All balls placed
    }
    return false; // else m!=0 all balls not placed
}

    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size(),ans =0;
        sort(pos.begin(),pos.end());
        int s =1, e = pos[n-1];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(mid,pos,m,n)){ // check given dist can be possible 
                ans =mid;
                s= mid+1;  // try for bigger dist
            }else e=mid-1; // try for smaller dist
        }
        return ans; 
    }
};