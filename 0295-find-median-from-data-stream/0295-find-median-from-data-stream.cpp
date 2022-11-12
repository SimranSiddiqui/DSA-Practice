class MedianFinder {
public:
   
    priority_queue<int> small;
    priority_queue<int ,vector<int>, greater<>> large;
    
    void addNum(int num) {
        small.push(num);
        
        if(!large.empty() && small.top() > large.top())
        {
            large.push(small.top());
            small.pop();
        }
        if(!small.empty() && small.size() > large.size()+1)          // small.size()-large.size() > 1  ??
        {
              large.push(small.top());
              small.pop();
        }
        else if(!large.empty() && large.size() > small.size()+1)      // large.size()-small.size() > 1  ??
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == large.size())
        {
            double n1 = small.top();
            double n2 = large.top();
            return (n1+n2)/2;
        }
        else if(small.size() > large.size())
        {
            double n = small.top();
            return n;
        }
        
    double n = large.top();
        return n;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */