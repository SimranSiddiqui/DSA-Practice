class SmallestInfiniteSet {
    
     priority_queue<int , vector<int>, greater<int>> pq;
    
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            pq.push(i);
    }
    
    int popSmallest() {
        int x = pq.top();
        while(!pq.empty() && pq.top() == x)
            pq.pop();
        
        return x;
    }
    
    void addBack(int num) {
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */