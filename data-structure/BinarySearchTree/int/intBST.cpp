#include "intBST.h"

bool IntBST::insertIntoBST(int val) {
    if (root == 0) {
        // empty tree
        root = new IntBSTNode(val);
        return true;
    }
    else {
        IntBSTNode *tmp = root;
        while(1) {
            if (val < tmp -> info) {
                if (tmp -> left != 0) {
                    tmp = tmp -> left;
                    continue;
                }
                else {
                    tmp -> left = new IntBSTNode(val);
                    return true;
                }
            }
            else if (val == tmp -> info) {
                return false;
            }
            else {
                if (tmp -> right != 0) {
                    tmp = tmp -> right;
                    continue;
                }
                else {
                    tmp -> right = new IntBSTNode(val);
                    return true;
                }
            }
        }
    }
}

bool IntBST::deleteFromBST(int) {
    // delete by merging
    return false;
}

void IntBST::preOrder(IntBSTNode *tmp, void (*func)(IntBSTNode*)) {
    if (tmp != 0) {
        func(tmp);
        preOrder(tmp -> left, func);
        preOrder(tmp -> right, func);
    }
}

void IntBST::midOrder(IntBSTNode *tmp, void (*func)(IntBSTNode*)) {
    if (tmp != 0) {
        midOrder(tmp -> left, func);
        func(tmp);
        midOrder(tmp -> right, func);
    }
}

void IntBST::postOrder(IntBSTNode *tmp, void (*func)(IntBSTNode*)) {
    if (tmp != 0) {
        postOrder(tmp -> left, func);
        postOrder(tmp -> right, func);
        func(tmp);
    }
}

void IntBST::breadthFirstOrder(void (*func)(IntBSTNode*)) {
    std::queue<IntBSTNode*> queue;
    IntBSTNode *tmp = root;
    if (tmp != 0) {
        queue.push(tmp);
        while (!queue.empty()) {
            tmp = queue.front();
            queue.pop();
            func(tmp);
            if (tmp -> left != 0)
                queue.push(tmp -> left);
            if (tmp -> right != 0)
                queue.push(tmp -> right);
        }
    }
}

int IntBST::maxLevel(IntBSTNode *node) {
    if (node == 0) return 0;
    else {
        return (maxLevel(node -> left) >= maxLevel(node -> right)) ?
            maxLevel(node -> left) + 1: maxLevel(node -> right) + 1;
    }
}

void IntBST::printNode(std::vector<IntBSTNode*>& nodes, int level, int max_level) {

    auto printWhiteSpaces = [](int x) {
        for (int i = 0; i < x; i ++) {
            std::cout << " ";
        }
    };

    if (nodes.empty() || [](const std::vector<IntBSTNode*> &nodes) -> bool {
            std::vector<IntBSTNode*>::const_iterator it = nodes.begin();
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

    std::vector<IntBSTNode*> new_nodes;
    std::vector<IntBSTNode*>::const_iterator it = nodes.begin();
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

void IntBST::printBST(IntBSTNode *tree) {
    int max_level = this -> maxLevel(tree);
    std::vector<IntBSTNode*> nodes;
    nodes.push_back(tree);
    printNode(nodes, 1, max_level);
}
