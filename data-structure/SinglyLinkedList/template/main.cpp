#include <iostream>
#include "templateSLList.h"
using namespace std;

int main() {
    templateSLList<int> testList;
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
    return 0;
}
