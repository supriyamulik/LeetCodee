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
public:
    bool isMirror(TreeNode* leftT, TreeNode* rightT)
    {
        if(leftT == NULL && rightT == NULL) return true;
        if(leftT == NULL || rightT == NULL) return false;

        return (leftT->val == rightT->val) && isMirror(leftT->left, rightT->right) && isMirror(leftT->right, rightT->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};