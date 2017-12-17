// Time : O(n)
// Space : O(n)

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int val = 0;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                val -= s.top();
                s.pop();
            }
            else if (ops[i] == "D") {
                int n = s.top();
                val += 2 * n;
                s.push(2 * n);
            }
            else if (ops[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
                val += a + b;
            }
            else {
                int n = stoi(ops[i]);
                s.push(n);
                val += n;
            }
        }
        
        return val;
    }
};