// Time : O(n^2 logn)
// Space : O(1)

class Solution {
private:
    // predicate : Are houses covered by heaters with radius r ?
    bool p(vector<int>& houses, vector<int>& heaters, int r) {
        for (int i = 0; i < houses.size(); i++) {
            bool canCover = false;
            for (int j = 0; j < heaters.size(); j++) {
                if ((houses[i] <= heaters[j] + r) && (houses[i] >= heaters[j] - r)) {
                    canCover = true;
                    break;
                }
            }
            if (!canCover) return false;
        }
        return true;
    }
    
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long lo = 0;
        long hi = INT_MAX;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (p(houses, heaters, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
