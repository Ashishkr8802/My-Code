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
    void storeInorder(TreeNode* root , vector<int> &inorder) {
        if(root == NULL) {
            return;
        }
        //LNR

        storeInorder(root->left , inorder);
        inorder.push_back(root->val);
        storeInorder(root->right , inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root , inorder);

        int start = 0;
        int end = inorder.size()-1;

        while(start < end) {
            if(inorder[start] + inorder[end] == k) {
                return true;
                break;
            }
            if(inorder[start] + inorder[end] < k) {
                start++;
            }
            else {
                end--;
            }
        }
        return false;
    }
};