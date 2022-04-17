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
    TreeNode * curr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * ans = new TreeNode;
        curr = ans;
        inorder(root);
        return ans->right;
    }
    
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            node->left = NULL;
            curr->right = node;
            curr = node;
            inorder(node->right);
        }
    }
    
};