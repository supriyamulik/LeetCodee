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

// creating a struct to store all teg infor about a per node 
    int maxSum = 0;
    struct Info{
        bool isBST;
        int minVal, maxVal, sum;
    };

    // a helper fun that will identify whether it is a bst if yes then minVal and maxVal and the sum and updating it 
    Info helper(TreeNode* root)
    {
        if(!root) return {true, INT_MAX, INT_MIN, 0};  // if root id null it is a bst 

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal) // if both left and right subtree are bst and max of left is smaller thn root and min of right is greater thaan root thsi is it is a bst
        {
            int currSum = left.sum + right.sum + root->val; // cal the sum
            maxSum = max(maxSum, currSum); 
            return {true, min(root->val, left.minVal), max(root->val, right.maxVal), currSum}; // update the maxsum nd minsum
        }
        return {false, 0, 0, 0};
    }
    int maxSumBST(TreeNode* root) 
    {
        helper(root);
        return maxSum;
    }
};