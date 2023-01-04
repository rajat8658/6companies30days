class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
       for(auto it:tokens) {
            if(it.size()>1 || isdigit(it[0])) 
                s.push(stoi(it));
            else {
                auto x2=s.top(); s.pop();
                auto x1=s.top(); s.pop();
                switch(it[0]) {
                    case '+': x1+=x2; break;
                    case '-': x1-=x2; break;
                    case '*': x1*=x2; break;
                    case '/': x1/=x2; break;
                }
                s.push(x1);
            }
        }
      return s.top();
    }
};