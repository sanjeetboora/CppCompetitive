class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {      
    }
    
    void addNum(int num) {
        
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      
         if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }    
    }
    
    double findMedian() {
       if(maxHeap.size()> minHeap.size()){
           return maxHeap.top();
        }
        else{
            return (minHeap.top() + maxHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */