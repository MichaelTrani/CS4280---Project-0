/*
Michael Trani 2/23/2020
*/
#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <stdio.h>


typedef struct tree{
    treeNode* root;
} tree;


treeNode* treeSeed(FILE*);

void makeNode(tree*, FILE*);
void insert(treeNode*, treeNode*);

void inOrder(treeNode*, char[]);
void printInorder(treeNode*, FILE*);

void preOrder(treeNode*, char[]);
void printPostorder(treeNode*, FILE*);

void postOrder(treeNode*, char[]);
void printPreorder(treeNode*, FILE*);

void printer(treeNode*, FILE*);


#endif