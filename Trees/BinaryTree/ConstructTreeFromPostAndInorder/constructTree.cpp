#include<iostream>
using namespace std;
#include"../BinaryTree.h"


BinaryTreeNode<int>* help(int* post, int* ino, int PostS, int PostE, int InS, int InE) {
    if(PostS > PostE) return NULL;

    int root {post[PostE]};
    int rootIndex {-1};
    for(int i{InS}; i<=InE; i++) {
        if(ino[i] == root) {
            rootIndex = i;
            break;
        }
    }
    int LeftInStart {InS};
    int LeftInEnd {rootIndex - 1};
    int LeftPostStart {PostS};
    int LeftPostEnd {LeftInEnd - LeftInStart + LeftPostStart};

    int RightPostStart {LeftPostEnd + 1};
    int RightPostEnd {PostE - 1};
    int RightInStart {rootIndex + 1};
    int RightInEnd {InE};

    BinaryTreeNode<int>* root_node {new BinaryTreeNode<int>(root)};
    root_node->left = help(post, ino, LeftPostStart, LeftPostEnd, LeftInStart, LeftInEnd);
    root_node->right = help(post, ino, RightPostStart, RightPostEnd, RightInStart, RightInEnd);
    return root_node;
}


BinaryTreeNode<int>* construct(int* post, int* ino, int size) {
    return help(post, ino, 0, size-1, 0, size-1);
}


int main() {
    int post[]{1,4,7,6,3,13,14,10,8};
    int ino[]{1,3,4,6,7,8,10,13,14};
    BinaryTreeNode<int>* root {construct(post, ino, sizeof(post)/sizeof(int))};
    print(root);
    delete root;
}