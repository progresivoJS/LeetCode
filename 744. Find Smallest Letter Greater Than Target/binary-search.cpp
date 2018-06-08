// Time : O(n)
// Space : O(1)

// Desc : lower bound for p(x) is true.

class Solution {
private:
    // predicate : letters[mid] > target
    bool p(vector<char>& letters, int mid, char target) {
        return letters[mid] > target;
    }
    
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (p(letters, mid, target)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        
        if (!p(letters, lo, target)) return letters[0];
        return letters[lo];
    }
};
