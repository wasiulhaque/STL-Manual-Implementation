#ifndef MWHbst
#define MWHbst

#ifndef _STDC
#include <bits/stdc++.h>
#endif
#ifndef _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _STDIO_H_
#include <stdio.h>
#endif

struct node
{
    int key;
    struct node *left, *right,*parent;
    int leftSize; // To count the rank
};

typedef struct node* Node;

Node newNode(int value)
{
    Node temp =  (Node)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = temp->right = NULL;
    temp->leftSize=0;
    return temp;
}

Node BSTinsert(Node node, int key)
{

    if (node == NULL)
        return newNode(key); //BST empty, create new node

    if (key <= node->key)
    {
        node->left  = BSTinsert(node->left, key); // Recursive call to left until found leaf node
        node->leftSize++;
    }
    else if (key > node->key)
        node->right = BSTinsert(node->right, key); // Recursive call to right until found leaf node
}

bool BSTfind(Node root, int key)
{
    if(root == "NULL"){
        return false; // No where to go, can not find
    }

     if (root->key == key){
        return true; // Found
    }

    if (root->key < key)
        return BSTfind(root->right, key); // If smaller, keep going to right until found
    return BSTfind(root->left, key); // If greater, keep going to left until found
}

int BSTfindMax(Node node)
{
    while (node->right != NULL) // Go to the right-most node
        node = node->right;

    return (node->key); // Key of the right-most node
}

int BSTfindMin(Node node)
{

    while (node->left != NULL) // Go to the left-most node
        node = node->left;

    return (node->key); // Key of the left-most node
}


Node nextLargerMinValue(Node node) // To find the smallest value of subtree on right child
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node; // If no left child of the right child, that child is the next larger
}


Node BSTnextLarger(Node root, Node n)
{
    Node temp=n->right;

    if( n->right != NULL ) // To check if it has any right subtree
    {
        temp= nextLargerMinValue(temp); // Find the smallest value in the subtree under right child
        return temp;
    }

    Node p = n->parent; // If right child doesn't exist, go to left
    while(p != NULL && n == p->right) // Check until we find such a parent that has a left child, and that parent contains the next larger
    {
        n = p;
        p = p->parent;
    }
    return p;
}


int BSTrank(Node root, int x)
{

    if (root->key == x)
        return root->leftSize;


    if (x < root->key)
    {
        if (!root->left)
            return -1;
        else
            return BSTrank(root->left, x);
    }

    else
    {
        if (!root->right)
            return -1;
        else
        {
            int rightSize = BSTrank(root->right, x);
            return root->leftSize + 1 + rightSize;
        }
    }
}


void BSTbfs(Node root)
{
    queue<node*> q;

    if (!root)
    {
        return;
    }
    for (q.push(root); !q.empty(); q.pop())
    {
        const node * const temp_node = q.front();
        printf("%d ",temp_node->key);


        if (temp_node->left)
        {
            q.push(temp_node->left);
        }
        if (temp_node->right)
        {
            q.push(temp_node->right);
        }
    }
}

void BSTdfs(Node node)
{
    if (node == NULL)
        return;


    cout << node->key << " ";


    BSTdfs(node->left);


    BSTdfs(node->right);
}
