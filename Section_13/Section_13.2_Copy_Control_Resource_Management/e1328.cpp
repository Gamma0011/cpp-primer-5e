#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    e13.28  - Given the following classes, implement a default constructor and the necessary copy-control members.

*/

class TreeNode {
public:
    TreeNode(const std::string &s,
             TreeNode l,
             TreeNode r) : value(s), left(new TreeNode(l)), right(new TreeNode(r)), count(1) { };

    TreeNode(TreeNode &tn) : value(tn.value), left(tn.left), right(tn.right) { ++tn.count; };

    TreeNode& operator=(TreeNode &tn) {
        ++tn.count;
        if (--count == 0) {
            delete left;
            delete right;
        }
        left = tn.left;
        right = tn.right;
        value = tn.value;
        count = tn.count;
        return *this;
    }

    ~TreeNode() {
        if (--count == 0) {
            delete left;
            delete right;
        }
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree(TreeNode r) : root(new TreeNode(r)) { };
    BinStrTree(const BinStrTree &b) : root(new TreeNode(b)) { };


private:
    TreeNode *root;
};

int main()
{


    return 0;
}