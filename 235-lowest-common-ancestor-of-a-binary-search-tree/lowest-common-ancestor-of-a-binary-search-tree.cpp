/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 Approach is to start traversing from the root go to left and right according to values and
 at a point we cnnot decide where tp go thaat is the point to return 
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return nullptr;
        int current = root->val;

        // both on the left
        if(p->val < current && q->val < current)
        {
            return lowestCommonAncestor(root->left, p, q);
        } 
        if(p->val > current && q->val > current)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};