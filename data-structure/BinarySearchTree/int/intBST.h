#ifndef _INT_BST_H_
#define _INT_BST_H_

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

class IntBSTNode {
    public:
        int info;
        IntBSTNode *left;
        IntBSTNode *right;

        IntBSTNode(int val, IntBSTNode *lp = 0, IntBSTNode *rp = 0) {
            info = val;
            left = lp;
            right = rp;
        } 
};

class IntBST {
    public:
        IntBSTNode *root;

        IntBST() {
            root = 0;
        };

        bool insertIntoBST(int);
        bool deleteFromBST(int);

        void preOrder(IntBSTNode*, void (*)(IntBSTNode*));
        void midOrder(IntBSTNode*, void (*)(IntBSTNode*));
        void postOrder(IntBSTNode*, void (*)(IntBSTNode*));
        void breadthFirstOrder(void (*)(IntBSTNode*));
        int maxLevel(IntBSTNode*);
        
        void printNode(std::vector<IntBSTNode*>&, int, int);
        void printBST(IntBSTNode*);
};

#endif
