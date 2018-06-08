// Time : O(m + n)
// Space : O(m + n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ret;
        unordered_set<int> set;
        for (int i = 0; i < nums1.size(); i++) {
            if (set.find(nums1[i]) == set.end()) {
                set.insert(nums1[i]);
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (set.find(nums2[i]) != set.end()) {
                ret.insert(nums2[i]);
            }
        }
        
        return vector<int>(ret.begin(), ret.end());
    }
};
