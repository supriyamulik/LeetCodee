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
    int preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd)
    {
        if(inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int inIndex = 0;
        for(int i = inStart; i<=inEnd; i++)
        {
            if(inorder[i] == root->val)
            {
                inIndex = i;
                break;
            }
        }
                    root->left = buildTree(preorder, inorder, inStart, inIndex-1);
            root->right = buildTree(preorder, inorder, inIndex+1, inEnd);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, inorder, 0, inorder.size() - 1);
    }
};