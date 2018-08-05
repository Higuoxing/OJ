#include <iostream>

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {};
};


class Solution {
        public:
                TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

                        if (!t1) return t2;
                        if (!t2) return t1;

                        TreeNode *head = new TreeNode(t1->val + t2->val);
                        head->left = mergeTrees(t1->left, t2->left);
                        head->right = mergeTrees(t1->right, t2->right);
                        return head;
                }

                void printTree(TreeNode* binTree) {
                        if (binTree != NULL) {
                                std::cout << binTree -> val << std::endl;
                                if (binTree -> left != NULL) {
                                        printTree(binTree -> left);
                                        printTree(binTree -> right);
                                } else if (binTree -> right != NULL) {
                                        printTree(binTree -> right);
                                } else {}
                        }
                }
};

int main(void) {
        TreeNode *head;
        head -> val = 1;
        head -> left = new TreeNode(2);
        head -> left -> left = new TreeNode(1);
        head -> left -> right = new TreeNode(4);
        head -> right = new TreeNode(3);
        Solution sol;
        sol.printTree(head);
        return 0;
}
