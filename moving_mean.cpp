//Question https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int> hmax;
    priority_queue<int, vector<int>, greater<int> > hmin;
    double mean = INT_MAX;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(num < mean)
            hmax.push(num);
        else
            hmin.push(num);
        
        // cout << hmax.size() << " " << hmin.size() << endl;
        if( (int)hmax.size() - (int)hmin.size() > 1){
            int ele = hmax.top();
            hmin.push(ele);
            hmax.pop();
        }
        else if ( (int)hmin.size() - (int)hmax.size() > 1){
            int ele = hmin.top();
            hmax.push(ele);
            hmin.pop();
        }
        
        mean = findMedian();
        // cout << "mean " << mean << endl;
            
    }
    
    double findMedian() {
        if(hmax.size() > hmin.size())
            return hmax.top();
        else if (hmax.size() < hmin.size())
            return hmin.top();
        else
            return (hmax.top() + hmin.top())/2.0;
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
