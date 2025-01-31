#ifndef BTREENODE_H
#define BTREENODE_H

#include <string>
#include <algorithm>
#include <vector>

struct BTreeNode {
    bool is_leaf_=true;
    std::vector<int> elements_;
    std::vector<BTreeNode*> children_;
    BTreeNode() {}
    BTreeNode (std::vector<int> v) {
      this->elements_ = v;
    }
};

BTreeNode* find(BTreeNode* root, int key);
BTreeNode* findc(std::vector<BTreeNode*> children_, int key);

#endif
