class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int,int>> s;
    int index =-1;
    
    int next(int price) {
        index++;
        if(s.empty())
        {
            s.push({price,index});
            return 1;
        }
        else
        {
            while(!s.empty() && s.top().first <= price)
            {
                s.pop();
            }
            
            if(s.empty())
            {
                s.push({price,index});
                return index +1;
            }
            else
            {
                  int span = index - s.top().second;
                  s.push({price,index});
                  return span;
            }
           
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */