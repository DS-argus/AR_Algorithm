class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        int val1, val2;
        for(auto& i : tokens){

            if(i=="+"){
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();

                s.push(val1+val2);

            }else if(i=="-"){
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();
                s.push(val1-val2);

            }else if(i=="*"){
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();

                s.push(val1*val2);

            }else if(i=="/"){
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();

                s.push(val1/val2);

            }else{
                
                s.push(stoi(i));

            }
        }

        return s.top();
    }
};