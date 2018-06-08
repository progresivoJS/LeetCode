// Time : O(n)
// Space : O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (int i = 0; i < t.length(); i++) {
            ret ^= t[i];
        }
        for (int i = 0; i < s.length(); i++) {
            ret ^= s[i];
        }
        return (char)ret;
    }
};