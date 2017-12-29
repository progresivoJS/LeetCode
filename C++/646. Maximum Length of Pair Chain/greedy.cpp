// Time : O(nlogn)
// Space : O(logn) (depending on sorting algorithm)

class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        
        int count = 1;
        int current = 0;
        for (int i = 1; i < n; i++) {
            if (pairs[current][1] < pairs[i][0]) {
                count++;
                current = i;
            }
        }
        
        return count;
    }
};
