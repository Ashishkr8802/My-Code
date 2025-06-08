/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }

        //if p and q both are in the left side
        if(p->val < root->val && q->val < root->val) {
            TreeNode* left = lowestCommonAncestor(root->left , p ,q);
            return left;
        }

        //if p and q both are in the right side
        if(p->val > root->val && q->val > root->val) {
            TreeNode* right = lowestCommonAncestor(root->right , p , q);
            return right;
        }

        //if p is in left  and q in the right

        if(p->val < root->val && q->val > root->val) {
            return root;
        }

        // if p is in the right and q in the left
        if(p->val > root->val && q->val < root->val) {
            return root;
        }

        return root;
    }
};