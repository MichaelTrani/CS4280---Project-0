/*
Michael Trani 2/23/2020
*/
#ifndef NODE_H
#define NODE_H

typedef struct treeNode {
    int key;
    int depth;
    char strings[10001];
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

#endif