/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        else {
            if (root->left == NULL) {
                TreeNode* node = root;
                root = root->right;
                delete node;
            } else if (root->right == NULL) {
                TreeNode* node = root;
                root = root->left;
                delete node;
            } else {
                TreeNode* node = root->right;
                while (node->left != NULL) {
                    node = node->left;
                }
                root->val = node->val;
                root->right = deleteNode(root->right, node->val);
            }
        }
    
    return root;
}
}
;