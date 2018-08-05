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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> runningQueue;
        vector<double> res;

        runningQueue.push(root);

        while (!runningQueue.empty()) {
            int len = runningQueue.size();
            long tmp = 0;
            for (int i = 0; i < len; i ++) {

                root = runningQueue.front();
                runningQueue.pop();

                tmp += root -> val;

                if (root -> left) runningQueue.push(root -> left);
                if (root -> right) runningQueue.push(root -> right);
            }
            res.push_back((double) tmp / len);
        }
        return res;
    }
};
