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
 #include<bits/stdc++.h>
class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        inorder(root->left);
        if(prev!=NULL && root->val < prev->val)
        {
            // taking the first voilation 
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            // if we already have the first voiltion here we got the second one 
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        // case 1 when both of them are now adjecent
        if(first && last) swap(first->val , last->val);

        // case 2 like when both re adjecent 
        else if(first && middle)
        {
            swap(first->val, middle->val);
        }
    }
};