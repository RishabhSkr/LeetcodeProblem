class MedianFinder {
public:
// arr me store krne pr size overflow ayega
// isiliye 2 pq will be used :
    priority_queue<int,vector<int>,greater<int>>maxHeap; // max half of the element
    priority_queue<int>minHeap; // min half of the element
    // vector<int>arr; //depreciated
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()<num)maxHeap.push(num);
        else minHeap.push(num);

        // balance the heap with equal element;
        if(maxHeap.size()>minHeap.size()+1){ // 7 / 6
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else{
            if(minHeap.size()>maxHeap.size()){   //7>6
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        
      if((minHeap.size()==maxHeap.size())){  // even size element present
        return (maxHeap.top()+minHeap.top())/2.0; 
      }else{
        return maxHeap.top(); // maxheap has more element.
      } 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */