class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();
        
        for(int i=0;i<n;i++)
        {
            if(operations[i] == "C" )
            {
                st.pop();
            }
            else if(operations[i] == "D")
            {
                st.push(st.top()*2);
            }
            else if(operations[i] == "+")
            {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.push(x1);
                st.push(x1+x2);
            }
            else
            {
                int x = stoi(operations[i]);
                st.push(x);
            }
        }
        
        int sum =0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};