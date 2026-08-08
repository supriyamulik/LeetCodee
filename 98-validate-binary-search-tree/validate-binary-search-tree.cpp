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
    bool findAns(TreeNode* root, long minValue, long maxValue)
    {
        if(root == nullptr) return true;    
        if(root->val <= minValue || root->val >= maxValue) return false;

        return findAns(root->left, minValue, root->val) && findAns(root->right, root->val, maxValue);
    }
    bool isValidBST(TreeNode* root) {
        return findAns(root, LONG_MIN, LONG_MAX);
        
    }
};