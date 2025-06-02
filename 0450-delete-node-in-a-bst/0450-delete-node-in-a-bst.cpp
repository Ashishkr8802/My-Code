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
    TreeNode* maxValue(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        TreeNode* temp = root;
        while(temp->right != NULL) {
            temp = temp->right;
        }

        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            else if(root->left != NULL && root->right == NULL) {
                TreeNode* childSubtree = root->left;
                delete root;
                return childSubtree;
            }

            else if(root->right != NULL && root->left == NULL) {
                TreeNode* childSubtree = root->right;
                delete root;
                return childSubtree;
            }

            else {
                //left subtree ki maximum value lao
                TreeNode* maxi = maxValue(root->left);
                //replacement
                root->val = maxi->val;
                //delete actual maxi wali node
                root->left = deleteNode(root->left , maxi->val);
                return root;
            }

        }
        else if(root->val > key) {
            //left me jana h
            root->left = deleteNode(root->left , key);
        }
        else {
            //right me jana h 
            root->right = deleteNode(root->right , key);
        }

        return root;
    }
};