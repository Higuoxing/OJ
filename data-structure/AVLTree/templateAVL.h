#ifndef _TEMPLATE_AVL_H_
#define _TEMPLATE_AVL_H_

#include <iostream>
#include <queue>
#include <vector>

template<typename T>
class templateAVLNode {
    public:
        T info;
        int height;
        templateAVLNode *left;
        templateAVLNode *right;

        templateAVLNode(T val, templateAVLNode *lp = 0, templateAVLNode *rp = 0) {
            info = val;
            left = lp;
            right = rp;
        } 
};

template<typename T>
class templateAVL {
    public:
        templateAVLNode<T> *root;

        templateAVL() {
            root = 0;
        }

        templateAVLNode<T>* insertIntoAVL(T, templateAVLNode<T>*);
        bool deletingByMerging(T);
        templateAVLNode<T>* balanceAVL(templateAVLNode<T>*);

        void preOrder(templateAVLNode<T>*, void (*)(templateAVLNode<T>*));
        void midOrder(templateAVLNode<T>*, void (*)(templateAVLNode<T>*));
        void postOrder(templateAVLNode<T>*, void (*)(templateAVLNode<T>*));
        void breadthFirstOrder(void (*)(templateAVLNode<T>*));

        templateAVLNode<T>* rrRot(templateAVLNode<T>*);
        templateAVLNode<T>* llRot(templateAVLNode<T>*);
        templateAVLNode<T>* rlRot(templateAVLNode<T>*);
        templateAVLNode<T>* lrRot(templateAVLNode<T>*);

        int maxLevel(templateAVLNode<T>*);
        void printNode(std::vector<templateAVLNode<T>*>&, int, int, void (*)(templateAVLNode<T>*));
        void printAVL(templateAVLNode<T>*, void (*)(templateAVLNode<T>*));
};

#endif

template<typename T>
templateAVLNode<T>* templateAVL<T>::insertIntoAVL(T val, templateAVLNode<T> *node) {
    /*
     * if empty tree:
     *     insert a node
     * else:
     *     if val > node -> info:
     *         insert into node -> right
     *         adjust height
     *     else if val < node -> info:
     *         insert into node -> right
     *         adjust height
     *     else return false
     *     node -> height = max_height of right or left + 1
     *     return true
     */
    if (node == 0) {
        node = new templateAVLNode<T>(val);
    } else if (val < node -> info) {
        node -> left = insertIntoAVL(val, node -> left);
        if (maxLevel(node -> left) - maxLevel(node -> right) == 2) {
            if (val < node -> left -> info) {
                node = llRot(node);
            } else {
                node = lrRot(node);
            }
        }
    } else if (val > node -> info) {
        node -> right = insertIntoAVL(val, node -> right);
        if (maxLevel(node -> right) - maxLevel(node -> left) == 2) {
            if (val > node -> right -> info) {
                node = rrRot(node);
            } else {
                node = rlRot(node);
            }
        }
    } else {
        
    }
    node -> height = (maxLevel(node -> right) >= maxLevel(node -> left)) ?
        maxLevel(node -> right) + 1: maxLevel(node -> left) + 1;
    return node;
}

template<typename T>
bool templateAVL<T>::deletingByMerging(T val) {
    // tracking deleting node
    templateAVLNode<T> *tmp = root;
    templateAVLNode<T> *node_prev;
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
    templateAVLNode<T> *node = tmp;
    templateAVLNode<T> *tmp_prev;
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

    if (maxLevel(node_prev -> left) - maxLevel(node_prev -> right) == 2) {
        if (maxLevel(node_prev -> left -> left) > maxLevel(node_prev -> left -> right)) {
            node_prev -> left = llRot(node_prev ->left);
        } else {
            node_prev -> left = lrRot(node_prev -> left);
        }
    } else if (maxLevel(node_prev -> right) - maxLevel(node_prev -> left) == 2) {
        if (maxLevel(node_prev -> right -> left) > maxLevel(node_prev -> right -> right)) {
            node_prev -> right = rlRot(node_prev -> right);
        } else {
            node_prev -> right= rrRot(node_prev -> right);
        }
    }
    return true;
}

template<typename T>
void templateAVL<T>::preOrder(templateAVLNode<T> *tmp, void (*func)(templateAVLNode<T>*)) {
    if (tmp != 0) {
        func(tmp);
        preOrder(tmp -> left, func);
        preOrder(tmp -> right, func);
    }
}

template<typename T>
void templateAVL<T>::midOrder(templateAVLNode<T> *tmp, void (*func)(templateAVLNode<T>*)) {
    if (tmp != 0) {
        midOrder(tmp -> left, func);
        func(tmp);
        midOrder(tmp -> right, func);
    }
}
template<typename T>
void templateAVL<T>::postOrder(templateAVLNode<T> *tmp, void (*func)(templateAVLNode<T>*)) {
    if (tmp != 0) {
        postOrder(tmp -> left, func);
        postOrder(tmp -> right, func);
        func(tmp);
    }
}

template<typename T>
int templateAVL<T>::maxLevel(templateAVLNode<T> *node) {
    if (node == 0) return 0;
    else {
        return (maxLevel(node -> left) >= maxLevel(node -> right)) ?
            maxLevel(node -> left) + 1: maxLevel(node -> right) + 1;
    }
}

template<typename T>
templateAVLNode<T>* templateAVL<T>::rrRot(templateAVLNode<T> *node) {
    templateAVLNode<T> *tmp;
    tmp = node -> right;
    node -> right = tmp -> left;
    tmp -> left = node;
    node -> height = (maxLevel(node -> right) >= maxLevel(node -> left)) ?
        maxLevel(node -> right) + 1: maxLevel(node -> left) + 1;
    return tmp;
}

template<typename T>
templateAVLNode<T>* templateAVL<T>::rlRot(templateAVLNode<T> *node) {
    node -> right = llRot(node -> right);
    return rrRot(node);
}

template<typename T>
templateAVLNode<T>* templateAVL<T>::lrRot(templateAVLNode<T> *node) {
    node -> left = rrRot(node -> left);
    return llRot(node);
}

template<typename T>
templateAVLNode<T>* templateAVL<T>::llRot(templateAVLNode<T> *node) {
    templateAVLNode<T> *tmp;
    tmp = node -> left;
    node -> left = tmp -> right;
    tmp -> right = node;
    node -> height = (maxLevel(node -> right) >= maxLevel(node -> left)) ?
        maxLevel(node -> right) + 1: maxLevel(node -> left) + 1;
    return tmp;
}

template<typename T>
void templateAVL<T>::printNode(std::vector<templateAVLNode<T>*> &nodes, int level, int max_level, void (*print)(templateAVLNode<T>*)) {

    auto printWhiteSpaces = [](int x) {
        for (int i = 0; i < x; i ++) {
            std::cout << " ";
        }
    };

    if (nodes.empty() || [](const std::vector<templateAVLNode<T>*> &nodes) -> bool {
            typename std::vector<templateAVLNode<T>*>::const_iterator it = nodes.begin();
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

    typename std::vector<templateAVLNode<T>*> new_nodes;
    typename std::vector<templateAVLNode<T>*>::const_iterator it = nodes.begin();
    for (; it != nodes.end(); ++ it) {
        if (*it != 0) {
            print(*it);
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
    printNode(new_nodes, level + 1, max_level, print);
}

template<typename T>
void templateAVL<T>::printAVL(templateAVLNode<T> *tree, void (*print)(templateAVLNode<T>*)) {
    int max_level = this -> maxLevel(tree);
    std::vector<templateAVLNode<T>*> nodes;
    nodes.push_back(tree);
    printNode(nodes, 1, max_level, print);
}
