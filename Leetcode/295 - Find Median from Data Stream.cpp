class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> mn;
    priority_queue<int, vector<int>> mx;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mn.empty()){
            mn.push(num);
            return;
        }
        if(num < mn.top()){
            mx.push(num);
        } else {
            mn.push(num);
        }

        while(mn.size() -1 > mx.size()){
            int x = mn.top();
            mn.pop();
            mx.push(x);
        }
        
        while(mn.size() < mx.size()){
            int x = mx.top();
            mx.pop();
            mn.push(x);
        }
    }
    
    double findMedian() {
        if(mn.size() == mx.size()){
            return 1.0*(mn.top() + mx.top())/2.0;
        } else {
            return 1.0*mn.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */