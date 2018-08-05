#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
#include <iostream>

class IntSLLNode {
    public:
        IntSLLNode() {
            next = NULL;
        }

        IntSLLNode(int el, IntSLLNode *ptr = NULL) {
            info = el;
            next = ptr;
        }

        int info;
        IntSLLNode *next;
};

class IntSLList {
    public:
        IntSLList() {
            head = tail = NULL;
        }

        IntSLList(int *array, int n);

        ~ IntSLList();

        bool isEmpty() {
            return head == NULL;
        }

        void addToHead(int);
        void addToTail(int);

        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int);
        bool isInList(int) const;
        void printSLList();

    private:
        IntSLLNode *head, *tail;
};

#endif
