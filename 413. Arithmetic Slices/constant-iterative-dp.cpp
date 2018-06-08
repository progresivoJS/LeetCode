// Time : O(n)
// Space : O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n <= 2) return 0;
        int a = (A[1] - A[0] == A[2] - A[1]) ? 1 : 0;
        int ret = a;
        for (int i = 3; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                a += 1;
                ret += a;
            }
            else {
                a = 0;
            }
        }
        return ret;
    }
};
