class MyCalendarThree {
public:
    map<int,int> mp;
    int c1=0;
    int maximum=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        for(auto a:mp){
            c1+=a.second;
            maximum = max(maximum,c1);
        }
        return maximum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */