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
    int count = 0;
    int BTC(TreeNode* root) {
        if(root == NULL) {
            return 1;
        }

        int ls = BTC(root->left);
        int rs = BTC(root->right);

        if(ls == -1 || rs == -1) {
            count++;
            return 0;
        }

        else if(ls == 1 && rs == 1) {
            return -1;
        }
        else {
            return 1;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(BTC(root) == -1) {
            count++;
        }
        return count;

    }
};