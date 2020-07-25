/*
    给定一个二叉树，求某个节点中序遍历的下一个节点的值
*/

#include <iostream>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
 };

class Solution {
public:
    char getNextValue(TreeNode *node) {
        if(node->right) {
            TreeNode *cur = node->right;
            while(cur->left)
                cur = cur->left;
            return cur->val;
        }

        else if(node->parent->left == node)
            return node->parent->val;
        else {
            while(node->parent && node->parent->left != node) {
                node = node->parent;
            }
            if(node->parent)
                return node->parent->val;
            else
                return '\0';
        }
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode('a');
    root->left = new TreeNode('b');
    root->right = new TreeNode('c');
    root->left->parent = root;
    root->right->parent = root;
    root->left->left = new TreeNode('d');
    root->left->right = new TreeNode('c');
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->left->right->left = new TreeNode('h');
    root->left->right->right = new TreeNode('i');
    root->left->right->left->parent = root->left->right;
    root->left->right->right->parent = root->left->right;
    root->right->left = new TreeNode('f');
    root->right->right = new TreeNode('g');
    root->right->left->parent = root->right;
    root->right->right->parent = root->right;

    Solution s;
    cout << s.getNextValue(root->left->right->right) << endl;
    return 0;
}

