#ifndef _TEMPLATE_SLL_H_
#define _TEMPLATE_SLL_H_
#include <iostream>

template<typename T>
class templateSLLNode {
    public:
        // var
        templateSLLNode *next;
        T info;

        // methods
        templateSLLNode() {
            next = NULL;
        }

        templateSLLNode(T val, templateSLLNode *ptr = NULL) {
            info = val;
            next = ptr;
        }
};

template<typename T>
class templateSLList {
    public:
        templateSLList() {
            head = tail = NULL;
        }

        ~ templateSLList();

        bool isEmpty() {
            return head == NULL;
        }

        void addToHead(T);
        void addToTail(T);

        T deleteFromHead();
        T deleteFromTail();
        void deleteNode(T);
        bool isInList(T) const;
        void printSLList();

    private:
        templateSLLNode<T> *head, *tail;
};

#endif

template<typename T>
templateSLList<T>::~ templateSLList() {
    for (templateSLLNode<T> *p; !isEmpty();) {
        p = head -> next;
        delete head;
        head = p;
    }
}

template<typename T>
void templateSLList<T>::addToHead(T val) {
    head = new templateSLLNode<T>(val, head);
    if (tail == NULL) {
        // if tail is a null pointer
        // (tail = head) -> NULL
        tail = head;
    }
}

template<typename T>
void templateSLList<T>::addToTail(T val) {
    if (tail != NULL) {
        tail -> next = new templateSLLNode<T>(val, NULL);
        tail = tail -> next;
    }
    else {
        head = tail = new templateSLLNode<T>(val);
    }
}

template<typename T>
T templateSLList<T>::deleteFromHead() {
    T val = head -> info;
    templateSLLNode<T> *tmp = head;
    if (head == tail) 
        // only one node in list
        head = tail = NULL;
    else head = head -> next;
    delete tmp;
    return val;
}

template<typename T>
T templateSLList<T>::deleteFromTail() {
    T val = tail -> info;
    if (head == tail) {
        // only one node in list
        delete head;
        head = tail = NULL;
    }
    else {
        templateSLLNode<T> *tmp;
        for (tmp = head; tmp -> next != tail; tmp = tmp -> next);
        delete tail;
        tail = tmp;
        tail -> next = NULL;
    }
    return val;
}

template<typename T>
void templateSLList<T>::deleteNode(T val) {
    if (head != NULL) {
        if (head == tail && val == head -> info) {
            // if only one node in list
            // and head -> info == searching info
            delete head;
            head = tail = NULL;
        }
        else if (val == head -> info) {
            // if more than one node in list
            templateSLLNode<T> *tmp = head;
            head = tmp -> next;
            delete tmp;
        }
        else {
            templateSLLNode<T> *pred, *tmp;
            for (pred = head, tmp = head -> next;
                    ((tmp != NULL) && !(tmp -> info == val));
                    pred = pred -> next, tmp = tmp -> next);
            if (tmp != NULL) {
                pred -> next = tmp -> next;
                delete tmp;
            }
        }
    }
}

template<typename T>
bool templateSLList<T>::isInList(T val) const {
    templateSLLNode<T> *tmp;
    for (tmp = head; (tmp != NULL) && (!(tmp -> info == val)); tmp = tmp -> next);
    return tmp != NULL;
}

template<typename T>
void templateSLList<T>::printSLList() {
    templateSLLNode<T> *tmp;
    if (head == tail) {
        // if only one node in list
        std::cout << "head(tail) -> NULL " << std::endl;
    }
    else {
        // if more one node in list
        std::cout << "head -> ";
        for (tmp = head; tmp != tail; tmp = tmp -> next) {
            std::cout << tmp -> info << " -> ";
        }
        std::cout << tail -> info;
        std::cout << " <- tail";
        std::cout << std::endl;
    }
}
