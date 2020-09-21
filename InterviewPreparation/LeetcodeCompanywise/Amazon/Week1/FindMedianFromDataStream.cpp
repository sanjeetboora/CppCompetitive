//https://leetcode.com/problems/find-median-from-data-stream/

/* using max and min heap */

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxp;
    priority_queue<int, vector<int>, greater<int> > minp;
    MedianFinder() {

    }

    void addNum(int num) {
        if (minp.size() > 0 and num >= minp.top()) {
            minp.push(num);
        }
        else {
            maxp.push(num);
        }
        if (maxp.size() < minp.size()) {
            maxp.push(minp.top());
            minp.pop();
        }
        else if (maxp.size() > (minp.size() + 1)) {
            minp.push(maxp.top());
            maxp.pop();
        }

    }

    double findMedian() {
        double res = 0;
        if (minp.size() == maxp.size()) {
            res = (minp.top() + maxp.top()) / 2.0;
        }
        else {
            res =  maxp.top();
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */