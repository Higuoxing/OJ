#include <iostream>
#include "templateBST.h"

using namespace std;

int main() {
    templateBST<int> testTree;
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
    cout << testTree.maxLevel(testTree.root);
    cout << endl;
    testTree.printBST(testTree.root);
    cout << endl;
    bool tmp;
    tmp = testTree.deletingByMerging(13);
    cout << endl;
    testTree.printBST(testTree.root);
    cout << endl;

    tmp = testTree.deletingByMerging(4);
    testTree.printBST(testTree.root);
    cout << endl;
    tmp = testTree.deletingByMerging(18);
    testTree.printBST(testTree.root);
    cout << endl;
    tmp = testTree.deletingByMerging(15);
    testTree.printBST(testTree.root);
    return 0;
}
