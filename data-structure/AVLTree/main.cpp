#include <iostream>
#include "templateAVL.h"

using namespace std;

int main() {
    templateAVL<int> testTree;
    testTree.root = testTree.insertIntoAVL(15, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(11, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(1, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(5, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(20, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(2, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(17, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(27, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(8, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(9, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(10, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    testTree.root = testTree.insertIntoAVL(11, testTree.root);
    testTree.root = testTree.insertIntoAVL(22, testTree.root);
    testTree.root = testTree.insertIntoAVL(99, testTree.root);
    testTree.root = testTree.insertIntoAVL(44, testTree.root);
    testTree.root = testTree.insertIntoAVL(33, testTree.root);
    testTree.root = testTree.insertIntoAVL(22, testTree.root);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    cout << endl;
    bool aa;
    aa = testTree.deletingByMerging(22);
    testTree.printAVL(testTree.root, [](templateAVLNode<int> *node){cout << node -> info;});
    cout << endl;

    return 0;
}
