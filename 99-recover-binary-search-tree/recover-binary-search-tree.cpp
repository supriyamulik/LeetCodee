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
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    } 
    void fixTree(TreeNode* root, vector<int>& ans, int& index)
    {
            if(root == NULL) return;

            fixTree(root->left, ans, index);
            root->val = ans[index++];
            fixTree(root->right, ans, index);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        sort(ans.begin(), ans.end());
        int index = 0;
        fixTree(root, ans, index);
    }
};