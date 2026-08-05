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

 // Level order traversal technique using teh queue ds just ensure tht at every itertion we put the left nd the right so here we have to keep the track of the leftest node so used the loop inside and keept the track of the lastest nod;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {        
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            int lastNode = 0;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                lastNode = node->val;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
            }
            ans.push_back(lastNode);
        }
    return ans;
    }
};