/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode * e1, * e2, * prev;
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(e1->val, e2->val);
    }
    void inorder(TreeNode * root) {
        if (!root) return;
        inorder(root->left);
        if (!e1 && prev->val > root->val) e1 = prev;
        if (e1 && prev->val > root->val) e2 = root;
        prev = root;
        inorder(root->right);
    }
};
