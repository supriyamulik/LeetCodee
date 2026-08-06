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
    TreeNode* findVal(TreeNode* root, int val)
    {
        if(root == nullptr) return nullptr;
        
        if(val == root->val) {
            return root;
        }
        else if(val < root->val) {
            return findVal(root->left, val);
        }
        else {
            return findVal(root->right, val);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return findVal(root, val);
    }
};
