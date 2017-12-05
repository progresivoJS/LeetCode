// Time : O(N^2)
// Space : O(N^2)

class Solution {
private:
    vector<vector<int>> cache;
    int isPalindrome(string& s, int start, int end) {
        if (start >= end)
            return true;
        if (s[start] != s[end])
            return false;
        
        int &ret = cache[start][end];
        if (ret != -1) return ret;
        
        return ret = isPalindrome(s, start + 1, end - 1);
    }
    
public:
    int countSubstrings(string s) {
        int n = s.length();
        cache = vector<vector<int>>(n, vector<int>(n, -1));
        int count = 0;
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                if (isPalindrome(s, start, end))
                    count++;
            }
        }
        
        return count;
    }
};
