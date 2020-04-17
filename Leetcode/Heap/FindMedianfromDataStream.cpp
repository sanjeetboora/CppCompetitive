class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {      
    }
    
    void addNum(int num) {
        
        if(minHeap.size() >=1 and num >= minHeap.top())  minHeap.push(num);
        else if(maxHeap.size() >=1 and num<=maxHeap.top()) maxHeap.push(num);
        else{
             maxHeap.push(num);
        }
       int s1 = maxHeap.size();
        int s2 = minHeap.size();
        
        if(s1 - s2 >=2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(s2 - s1 >=2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
         
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top())/2.0;
        }
        else{
            if(maxHeap.size()> minHeap.size()){
                return maxHeap.top();
            }
            else{
                 return minHeap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */








 