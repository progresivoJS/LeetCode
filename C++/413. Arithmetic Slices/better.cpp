// Time : O(n^2)
// Space : O(1)

class Solution {
private:
    int countSeq(vector<int>& A, int start) {
        int count = 0;
        int d = A[start + 1] - A[start];
        for (int i = start + 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == d) count++;
            else return count;
        }
        return count;
    }
    
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = 0;
        int n = A.size();
        for (int i = 0; i < n - 2; i++) {
            count += countSeq(A, i);
        }
        return count;
    }
};
