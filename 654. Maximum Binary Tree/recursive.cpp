// Time : from O(nlogn) to O(n^2)
// Space : O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int index = -1;
        int maximum = INT_MIN;
        for (int i = lo; i <= hi; i++) {
            if (maximum < nums[i]) {
                maximum = nums[i];
                index = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[index]);
        root->left = helper(nums, lo, index - 1);
        root->right = helper(nums, index + 1, hi);
        return root;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};