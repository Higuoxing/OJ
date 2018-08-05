#include "intSLList.h"

IntSLList::IntSLList(int *array, int n) {
    for (int i = 0; i < n; i ++) {
        addToTail(array[i]);
    }
}

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty();) {
        p = head -> next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el, head);
    if (tail == NULL) {
        // if tail is a null pointer
        // (tail = head) -> Node
        tail = head;
    }
}

void IntSLList::addToTail(int el) {
    if (tail != NULL) {
        tail -> next = new IntSLLNode(el, NULL);
        tail = tail -> next;
    }
    else {
        head = tail = new IntSLLNode(el);
    }
}

int IntSLList::deleteFromHead() {
    int val = head -> info;
    IntSLLNode *tmp = head;
    if (head == tail) 
        // only one node in SLList
        head = tail = NULL;
    else head = head -> next;
    delete tmp;
    return val;
}

int IntSLList::deleteFromTail() {
    int val = tail -> info;
    if (head == tail) {
        delete head;
        head = tail = NULL;
    }
    else {
        IntSLLNode *tmp;
        for (tmp = head; tmp -> next != tail; tmp = tmp -> next);
        delete tail;
        tail = tmp;
        tail -> next = NULL;
    }
    return val;
}

void IntSLList::deleteNode(int el) {
    if (head != NULL) {
        if (head == tail && el == head -> info) {
            // if only one node in SLList
            delete head;
            head = tail = NULL;
        }
        else if (el == head -> info) {
            // if more than one node in SLList
            IntSLLNode *tmp = head;
            head = tmp -> next;
            delete tmp;
        }
        else {
            IntSLLNode *pred, *tmp;
            for (pred = head, tmp = head -> next;
                    ((tmp != NULL) && !(tmp -> info == el));
                    pred = pred -> next, tmp = tmp -> next);
            if (tmp != NULL) {
                pred -> next = tmp -> next;
                if (tmp == tail) tail = pred;
                delete tmp;
            }
        }
    }
}

bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; (tmp != NULL) && (!(tmp -> info == el)); tmp = tmp -> next);
    return tmp != NULL;
}

void IntSLList::printSLList() {
    IntSLLNode *tmp;
    if (head == tail) {
        // if only one node in list
        std::cout << "head(tail) -> NULL" << std::endl;
    }
    else {
        // if more than one nodes in list
        std::cout << "head -> ";
        for (tmp = head; tmp != tail; tmp = tmp -> next) {
            std::cout << tmp -> info << " -> ";
        }
        std::cout << tail -> info;
        std::cout << " <- tail";
        std::cout << std::endl;
    }
}
