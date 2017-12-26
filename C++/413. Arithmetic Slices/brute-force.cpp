// Time : O(n^3)
// Space : O(1)

class Solution {
private:
    bool isArithmetic(vector<int>& A, int lo, int hi) {
        int d = A[lo + 1] - A[lo];
        for (int i = lo + 1; i <= hi; i++) {
            if (A[i] - A[i - 1] != d) {
                return false;
            }
        }
        return true;
    }
    
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (isArithmetic(A, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
