#include <iostream>
#include "intBST.h"

using namespace std;

void TestFunc(IntBSTNode* node) {
    cout << node -> info;
}

int main() {
    IntBST testTree;
    cout << testTree.insertIntoBST(15);
    cout << testTree.insertIntoBST(6);
    cout << testTree.insertIntoBST(18);
    cout << testTree.insertIntoBST(3);
    cout << testTree.insertIntoBST(7);
    cout << testTree.insertIntoBST(2);
    cout << testTree.insertIntoBST(4);
    cout << testTree.insertIntoBST(13);
    cout << testTree.insertIntoBST(9);
    cout << testTree.insertIntoBST(17);
    cout << testTree.insertIntoBST(20);
    cout << endl;
    testTree.preOrder(testTree.root, TestFunc);
    cout << endl;
    testTree.midOrder(testTree.root, TestFunc);
    cout << endl;
    testTree.postOrder(testTree.root, [](IntBSTNode *node){cout << node->info << '\t';});
    cout << endl;
    cout << testTree.maxLevel(testTree.root);
    cout << endl;
    testTree.printBST(testTree.root);
    return 0;
}
