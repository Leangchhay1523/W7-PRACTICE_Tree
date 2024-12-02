#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree(int value) {
        root = new Node(value);
    }
    void insertLeft(int value) {
        root->left = new Node(value);
    }
    void insertRight(int value) {
        root->right = new Node(value);
    }

    std::string inOrderTraverse() {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    std::string preOrderTraverse() {
        std::string result = "";
        preOrder(root, result);
        return result;
    }
    std::string postOrderTraverse() {
        std::string result = "";
        postOrder(root, result);
        return result;
    }

    Node* getroot() {
        return root;
    }


private:
    void inOrder(Node* node, std::string& result) {
        //your code here // Left -> Root -> Right
        if (node->left != nullptr)
            inOrder(node->left, result);
        
        result += to_string(node->data);
        result += " ";

        if (node->right != nullptr)
            inOrder(node->right, result);
    };
    void preOrder(Node* node, std::string& result) {
        //your code here // Root -> Left -> Right
        result += to_string(node->data);
        result += " ";

        if (node->left != nullptr)
            preOrder(node->left, result);

        if (node->right != nullptr)
            preOrder(node->right, result);
    };
    void postOrder(Node* node, std::string& result) {
        //your code here // Left -> Right -> Root
        if (node->left != nullptr)
            postOrder(node->left, result);

        if (node->right != nullptr)
            postOrder(node->right, result);

        result += to_string(node->data);
        result += " ";
    }
};

#endif // BINARYTREE_H
