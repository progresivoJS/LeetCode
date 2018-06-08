// Time : O(nlogn)
// Space : O(1)

class Solution {
private:
    // predicate : a <= b
    bool p(int a, int b) {
        return a <= b;
    }
    
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int lo = i + 1;
            int hi = numbers.size() - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (p(target-numbers[i], numbers[mid])) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            
            if (numbers[i] + numbers[lo] == target) {
                return vector<int> {i + 1, lo + 1};
            }
        }
    }
};
