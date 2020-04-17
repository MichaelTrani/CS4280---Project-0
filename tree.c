/*
Michael Trani 2/23/2020
This file contains the functions for building, populating, and sorting trees.
It also contains the function to output the tree to the outfile.

*/

#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* treeSeed()
creates tree struct
takes file pointer and passes it to makeNode until EOF
Returns tree struct
Used in: p0.c
*/
treeNode* treeSeed(FILE* infile) {
    tree binaryTree = { .root = NULL };
    
    do{    
        makeNode(&binaryTree, infile);
    } while (!feof(infile));

    return binaryTree.root;
}


/* makeNode()
creates str inString to take from file passed in for key
creates a new node and poplulates children as NULL
sets node.key based on the length of the inString
inserts node into tree passed in
Used in: treeSeed()
*/
void makeNode(tree* inTree, FILE* infile) {

    #define STRINGSIZE 100

    char inString[STRINGSIZE];
    fscanf(infile, "%s", inString);

    treeNode* node = (treeNode*)malloc(sizeof(treeNode));

    node->left = NULL;
    node->right = NULL;

    node->key = strlen(inString);
    strcpy(node->strings, inString);
    if (inTree->root == NULL) {
        inTree->root = node;
    }
    else {
        insert(node, inTree->root);
    }
}


/* insert()
Compares keys of passed nodes
If equal, string is absorbed by current node
otherwise continues to appropiate child
Used in: makeNode()
*/
void insert(treeNode* nodeA, treeNode* nodeB) {

    if (nodeA->key == nodeB->key) {

        if (strstr(nodeB->strings, nodeA->strings) == NULL) {

            strcat(nodeB->strings, " ");
            strcat(nodeB->strings, nodeA->strings);
        }
    }

    nodeA->depth = (nodeB->depth + 1);
    if (nodeA->key < nodeB->key) {

        if (nodeB->left == NULL) {
            nodeB->left = nodeA;
        }
        else {
            insert(nodeA, nodeB->left);
        }
    }

    if (nodeA->key > nodeB->key) {

        if (nodeB->right == NULL) {
            nodeB->right = nodeA;
        }
        else {
            insert(nodeA, nodeB->right);
        }
    }
        
}


/* printer()
Formatting for output
Called by print*order()s
*/
void printer(treeNode* node, FILE* outfile) {
    int spacing = (node->depth) * 2;
    
    char spaceBar[200];  // Inline to bypass an error
    int j;
    for (j = 0; j < spacing; j++) {
        spaceBar[j] = ' ';
    }
    spaceBar[j] = '\0';

    fprintf(outfile, "%d)%s%s\n",node->key, spaceBar, node->strings);
    
   
}


/* preOrder()
This function works as file management for printPreorder()
Called by p0.c
*/
void preOrder(treeNode* node, char fname[]) {
    FILE* outf1 = fopen(fname, "w");
    if (!outf1) {
        printf("Unable to open %s for output.\n", fname);
        exit(1);
    }

    printPreorder(node, outf1);
    fclose(outf1);
}


/* printPreorder()
Required function. Goes through tree and sends to printer()
Called by: preOrder()
*/
void printPreorder(treeNode* node, FILE* outfile) {
    if (node == NULL)
        return;
    else{
        printer(node, outfile);
        printPreorder(node->left, outfile);
        printPreorder(node->right, outfile);
    }
}


/* inOrder()
This function works as file management for printInorder()
Called by p0.c
*/
void inOrder(treeNode* node, char fname[]) {
    FILE *outf2 = fopen(fname, "w");
    if (!outf2) {
        printf("Unable to open %s for output.\n", fname);
        exit(1);
    }
    printInorder(node, outf2);
    fclose(outf2);
}


/* printInorder()
Required function. Goes through tree and sends to printer()
Called by: inOrder()
*/
void printInorder(treeNode* node, FILE* outfile) {
    if (node == NULL)
        return;
    else {
        printInorder(node->left, outfile);
        printer(node, outfile);
        printInorder(node->right, outfile);
    }
}


/* postOrder()
This function works as file management for printPostorder()
Called by p0.c
*/
void postOrder(treeNode* node, char fname[]) {

    FILE *outf3 = fopen(fname, "w");
    if (!outf3) {
        printf("Unable to open %s for output.\n", fname);
        exit(1);
    }
    printPostorder(node, outf3);
    fclose(outf3);
}


/* printPostorder()
Required function. Goes through tree and sends to printer()
Called by: postOrder()
*/
void printPostorder(treeNode* node, FILE* outfile) {
    if (node == NULL)
        return;
    else {
        printPostorder(node->left, outfile);
        printPostorder(node->right, outfile);
        printer(node, outfile);
    }
}