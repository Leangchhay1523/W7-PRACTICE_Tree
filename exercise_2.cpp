#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

// Function generate random direction
int generateARandomDirection()
{
    return rand() % 2;
}

// Function to insert value at random position
void insertValueOn(Node* node, int value)
{
    int direction = generateARandomDirection(); // 1 = Left, 0 = Right

    if (direction == 1) // Left
    {
        if (node->left != nullptr)
        {
            insertValueOn(node->left, value);
        }
        else 
        {
            node->left = new Node(value);
        }
    }
    else // Right
    {
        if (node->right != nullptr)
        {
            insertValueOn(node->right, value);
        }
        else 
        {
            node->right = new Node(value);
        }
    }
}

// Function to return a generated tree
BinaryTree generateTree(int* arr50Nums, int element)
{
    BinaryTree tree(arr50Nums[0]);
    Node* root = tree.getroot();
    for (int i = 1; i < element; i++)
    {
        insertValueOn(root, arr50Nums[i]);
    }

    return tree;
}

// Function to print Tree
string printTree(Node* root, string space = "") {
    string treeStr;
    static int count = 0; // Declare once
    treeStr += space; 
    string childSpace;
    if (count == 0) // For tree root, we have to print data first before |_
    {
        treeStr += to_string(root->data);
        treeStr += "\n";
    }
    else 
    {
        treeStr += "|_";
        treeStr += to_string(root->data);
        treeStr += "\n";
        childSpace = space + "  ";
    }
    count++;
    if (root->left != nullptr)
        treeStr += printTree(root->left, childSpace);
    if (root->right != nullptr)
        treeStr += printTree(root->right, childSpace);
    return treeStr;
}

//Function to find height of the Tree
int findHeight(Node* root)
{
    if (root == nullptr)
        return 0;
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    // Generate Tree with 50 nodes
    int *arr50Nums = new int[50];
    for (int i = 0; i < 50; i++)
    {
        arr50Nums[i] = (rand() % 50) + 1;
    }
    BinaryTree tree50 = generateTree(arr50Nums, 50);
    cout << "Tree with 50 nodes : " << endl;
    cout << printTree(tree50.getroot());

    // Generate Tree with 1000 nodes
    int *arr1000Nums = new int[1000];
    for (int i = 0; i < 100; i++)
    {
        arr1000Nums[i] = (rand() % 1000) + 1;
    }
    BinaryTree tree1000 = generateTree(arr1000Nums, 1000);
    cout << "Height : " << findHeight(tree1000.getroot());
}