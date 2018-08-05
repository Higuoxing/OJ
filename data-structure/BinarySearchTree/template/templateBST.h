#ifndef _TEMPLATE_BST_H_
#define _TEMPLATE_BST_H_

#include <iostream>
#include <queue>
#include <vector>

template<typename T>
class templateBSTNode {
    public:
        T info;
        templateBSTNode *left;
        templateBSTNode *right;

        templateBSTNode(T val, templateBSTNode *lp = 0, templateBSTNode *rp = 0) {
            info = val;
            left = lp;
            right = rp;
        } 
};

template<typename T>
class templateBST {
    public:
        templateBSTNode<T> *root;

        templateBST() {
            root = 0;
        }

        bool insertIntoBST(T);
        bool deletingByMerging(T);

        void preOrder(templateBSTNode<T>*, void (*)(templateBSTNode<T>*));
        void midOrder(templateBSTNode<T>*, void (*)(templateBSTNode<T>*));
        void postOrder(templateBSTNode<T>*, void (*)(templateBSTNode<T>*));
        void breadthFirstOrder(void (*)(templateBSTNode<T>*));

        templateBSTNode<T>* rrRot(templateBSTNode<T>*);
        templateBSTNode<T>* llRot(templateBSTNode<T>*);
        templateBSTNode<T>* rlRot(templateBSTNode<T>*);
        templateBSTNode<T>* lrRot(templateBSTNode<T>*);

        int maxLevel(templateBSTNode<T>*);
        void printNode(std::vector<templateBSTNode<T>*>&, int, int);
        void printBST(templateBSTNode<T>*);
};

#endif

template<typename T>
bool templateBST<T>::insertIntoBST(T val) {
    if (root == 0) {
        // empty tree
        root = new templateBSTNode<T>(val);
        return true;
    } else {
        templateBSTNode<T> *tmp = root;
        while (1) {
            if (val < tmp -> info) {
                if (tmp -> left != 0) {
                    tmp = tmp -> left;
                    continue;
                } else {
                    tmp -> left = new templateBSTNode<T>(val);
                    return true;
                }
            } else if (val == tmp -> info) {
                return false;
            } else {
                if (tmp -> right != 0) {
                    tmp = tmp -> right;
                    continue;
                } else {
                    tmp -> right = new templateBSTNode<T>(val);
                    return true;
                }
            } 
        }
    }
}

template<typename T>
bool templateBST<T>::deletingByMerging(T val) {
    // tracking deleting node
    templateBSTNode<T> *tmp = root;
    templateBSTNode<T> *node_prev;
    if (val == root -> info) return false;
    while (tmp != 0) {
        if (val < tmp -> info) {
            node_prev = tmp;
            tmp = tmp -> left;
        } else if (val > tmp -> info) {
            node_prev = tmp;
            tmp = tmp -> right;
        } else break;
    }
    if (tmp == 0) return false;
    templateBSTNode<T> *node = tmp;
    templateBSTNode<T> *tmp_prev;
    if (node -> right == 0) {
        if (node_prev -> left == node) node_prev -> left = node -> left;
        else node_prev -> right = node -> left;
    } else if (node -> left == 0) {
        if (node_prev -> left == node) node_prev -> left = node -> right;
        else node_prev -> right = node -> right;
    } else {
        tmp = tmp -> left;
        while (tmp != 0) {
            if (tmp -> right != 0) {
                tmp_prev = tmp;
                tmp = tmp -> right;
            } else {
                tmp -> right = node -> right;
                if (node_prev -> left == node) node_prev -> left = node -> left;
                else node_prev -> right = node -> left;
                break;
            }
        }
    }
    delete node;
    return true;
}

template<typename T>
void templateBST<T>::preOrder(templateBSTNode<T> *tmp, void (*func)(templateBSTNode<T>*)) {
    if (tmp != 0) {
        func(tmp);
        preOrder(tmp -> left, func);
        preOrder(tmp -> right, func);
    }
}

template<typename T>
void templateBST<T>::midOrder(templateBSTNode<T> *tmp, void (*func)(templateBSTNode<T>*)) {
    if (tmp != 0) {
        midOrder(tmp -> left, func);
        func(tmp);
        midOrder(tmp -> right, func);
    }
}
template<typename T>
void templateBST<T>::postOrder(templateBSTNode<T> *tmp, void (*func)(templateBSTNode<T>*)) {
    if (tmp != 0) {
        postOrder(tmp -> left, func);
        postOrder(tmp -> right, func);
        func(tmp);
    }
}

template<typename T>
int templateBST<T>::maxLevel(templateBSTNode<T> *node) {
    if (node == 0) return 0;
    else {
        return (maxLevel(node -> left) >= maxLevel(node -> right)) ?
            maxLevel(node -> left) + 1: maxLevel(node -> right) + 1;
    }
}

template<typename T>
templateBSTNode<T>* templateBST<T>::rrRot(templateBSTNode<T> *node) {
    templateBSTNode<T> *tmp;
    tmp = node -> right;
    node -> right = tmp -> left;
    tmp -> left = node;
    return tmp;
}

template<typename T>
templateBSTNode<T>* templateBST<T>::rlRot(templateBSTNode<T> *node) {
    node -> right = llRot(node -> right);
    return rrRot(node);
}

template<typename T>
templateBSTNode<T>* templateBST<T>::lrRot(templateBSTNode<T> *node) {
    node -> left = rrRot(node -> left);
    return llRot(node);
}

template<typename T>
templateBSTNode<T>* templateBST<T>::llRot(templateBSTNode<T> *node) {
    templateBSTNode<T> *tmp;
    tmp = node -> left;
    node -> left = tmp -> right;
    tmp -> right = node;
    return tmp;
}

template<typename T>
void templateBST<T>::printNode(std::vector<templateBSTNode<T>*> &nodes, int level, int max_level) {

    auto printWhiteSpaces = [](int x) {
        for (int i = 0; i < x; i ++) {
            std::cout << " ";
        }
    };

    if (nodes.empty() || [](const std::vector<templateBSTNode<T>*> &nodes) -> bool {
            typename std::vector<templateBSTNode<T>*>::const_iterator it = nodes.begin();
            while (it != nodes.end()) {
            if (*it) return false;
            ++ it;
            }
            return true;
            } (nodes)) return;

    int floor = max_level - level;
    int edge_lines = 1 << ([](int x0, int x1) -> int {
            return (x0 >= x1)? x0: x1;
            } (floor - 1, 0));
    int first_spaces = (1 << floor) - 1;
    int between_spaces = (1 << (floor + 1)) - 1;

    printWhiteSpaces(first_spaces);

    typename std::vector<templateBSTNode<T>*> new_nodes;
    typename std::vector<templateBSTNode<T>*>::const_iterator it = nodes.begin();
    for (; it != nodes.end(); ++ it) {
        if (*it != 0) {
            std::cout << (*it) -> info;
            new_nodes.push_back((*it) -> left);
            new_nodes.push_back((*it) -> right);
        }
        else {
            new_nodes.push_back(0);
            new_nodes.push_back(0);
            std::cout << " ";
        }
        printWhiteSpaces(between_spaces);
    }
    std::cout << std::endl;

    for (int i = 1; i <= edge_lines; i ++) {
        for (int j = 0; j < nodes.size(); j ++) {
            printWhiteSpaces(first_spaces - i);
            if (nodes[j] == 0) {
                printWhiteSpaces(2*edge_lines + i + 1);
                continue;
            }
            if (nodes[j] -> left != 0) std::cout << "/";
            else printWhiteSpaces(1);
            printWhiteSpaces(2*i - 1);

            if (nodes[j] -> right != 0) std::cout << "\\";
            else printWhiteSpaces(1);
            printWhiteSpaces(2*edge_lines - i);
        }
        std::cout << std::endl;
    }
    printNode(new_nodes, level + 1, max_level);
}

template<typename T>
void templateBST<T>::printBST(templateBSTNode<T> *tree) {
    int max_level = this -> maxLevel(tree);
    std::vector<templateBSTNode<T>*> nodes;
    nodes.push_back(tree);
    printNode(nodes, 1, max_level);
}
