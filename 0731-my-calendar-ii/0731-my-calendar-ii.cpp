class MyCalendarTwo {
public:
    vector<vector<int>>bookings;
    vector<vector<int>>overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //  Check if this booking would cause a triple booking
        for(auto &x: overlap){
            int s =x[0];
            int e = x[1];
            if(max(s,start)<min(end,e)){
                return false;
            }
        }
        // check overall booking if overlapping the curr push it into overlap 
        for(auto x: bookings){
               int s =x[0];
            int e = x[1];
            if(max(s,start)<min(end,e)){
                  // Add this overlap to the overlap list
                overlap.push_back({max(start,s),min(end,e)});
            }
        }
         // If no triple booking found, add the new booking
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */