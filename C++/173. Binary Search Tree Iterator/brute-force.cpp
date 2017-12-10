// Time : Constructor : O(n), hasNext, next : O(1)
// Space : O(n)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    queue<int> inorder;
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        inorder.push(root->val);
        traverse(root->right);
    }
    
public:
    BSTIterator(TreeNode *root) {
        traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !inorder.empty();
    }

    /** @return the next smallest number */
    int next() {
        int val = inorder.front();
        inorder.pop();
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */