#include <iostream>
#include "intSLList.h"
using namespace std;

int main() {
    IntSLList testList;
    testList.printSLList();
    cout << "tesing isEmpty?" << '\t';
    cout << testList.isEmpty() << endl;
    cout << "adding 0, 1 to tail..." << endl;
    testList.addToTail(0);
    testList.addToTail(1);
    testList.printSLList();
    cout << "tesing isEmpty?" << '\t';
    cout << testList.isEmpty() << endl;
    cout << "adding 0, 1 to head..." << endl;
    testList.addToHead(0);
    testList.addToHead(1);
    testList.printSLList();
    cout << "deleting from head..." << endl;
    testList.deleteFromHead();
    testList.printSLList();
    cout << "deleting from tail..." << endl;
    testList.deleteFromTail();
    testList.printSLList();
    cout << "testing if 0 in list..." << endl;
    cout << testList.isInList(0) << endl;
    cout << "testing if 1 in list..." << endl;
    cout << testList.isInList(1) << endl;
    testList.printSLList();
    cout << "deleting 0 from list..." << endl;
    testList.deleteNode(0);
    testList.printSLList();
    cout << "adding 0, 1, 2, 3 to list..." << endl;
    int array[] = {0, 1,2, 3};
    IntSLList testList_1(array, 4);
    testList_1.printSLList();
    return 0;
}
