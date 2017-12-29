// Time : O(n^2)
// Space : O(n)

class Solution {
private:
    vector<int> cache;
    
    int chain(vector<vector<int>>& pairs, int start) {
        int& ret = cache[start];
        if (ret != -1) return ret;
        
        int res = 1;
        for (int next = start + 1; next < pairs.size(); next++) {
            if (pairs[start][1] < pairs[next][0]) {
                res = max(res, 1 + chain(pairs, next));
            }
        }
        
        return ret = res;
    }
    
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        cache = vector<int>(n, -1);
        int ret = 0;
        for (int start = 0; start < n; start++) {
            ret = max(ret, chain(pairs, start));
        }
        return ret;
    }
};
