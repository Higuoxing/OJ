/**
 * File              : Solution.cc
 * Author            : Xing GUO <higuoxing@seu.edu.cn>
 * Date              : 15.01.2018
 * Last Modified Date: 15.01.2018
 * Last Modified By  : Xing GUO <higuoxing@seu.edu.cn>
 */

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int right = maxDepth(root -> right);
        int left = maxDepth(root -> left);
        return right >= left ? \
            right + 1 : left + 1;
    }
};
