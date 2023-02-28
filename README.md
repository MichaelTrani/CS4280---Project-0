Michael Trani 2/23/2020

This program populates a binary search tree with strings provided by the user as described in Reference 01.
The user may use a pre-populated file with the extension .sp2020 by entering 
the file name without the extension as an argument from the command line.

Example: ./p0 myFile
This will tell p0 to take input from myFile.sp2020

If no file name is provided, keyboard input will be required.
When finished with keyboard input, press Ctrl+D. Possibly four times if necessary.
Once the tree has been built, the program will output the preorder, inorder, and postorder
trees to a file with the appropiate extention.
Output Format:
    [String Size])[white space corresponding to 2x node depth][strings in node]



Note:
This program limits a string to 100 chars.
This program limits keyboard input to 10000 characters.
This program limits the tree's string storage to 10000 characters.
This is assumed to be large enough to satisfy testing conditions.
Output includses a closed parenthsis for better readbility of outfile since 
the root node is zero and will not have spaces for indentation.


Author's Note:
This is my first C program in ~4 years or so.
Methods may be clunky or even sloppy while trying to rebuild language knowledge
Spelling errors in comments may be attributed to a combination of mental fatigue, illness, and poor spelling skills.
*/

/*############################### REFERENCE 01

    Proj0.cpp : This file contains the 'main' function. Program execution begins and ends there.


    Write a program to build a tree and print it using different traversals

    * The program will be invoked as P0 [file] where file is an optional argument.
    * If the file argument is not given, the program reads data from the keyboard as a device
    * If the argument is given, the program reads data file file.sp2020. (note that file is any name and the extension is implicit).
    * Assume you do not know the size of the input file
    * Assume the input data is all strings separated with standard WS separators (space, tab, new line)
    * If the input file is not readable for whatever reason, or command line arguments are not correct, the program must abort with an appropriate message
    * The program will read the data left to right and put them into a tree, which is a binary search tree (BST) with respect to the string length.
        - that is all strings of the same length are falling into the same node in the BST.
        - Tree is never balanced nor restructured other than growing new nodes.
        - A node should contain all data that falls into the node except that literally the same strings will show up only once ( the node contains the set of data falling into the node).

    * The program will subsequently output 3 files corresponding to 3 traversals named:
        file.preorder
        file.inorder
        file.postorder.
        - Note that file is the base name of the input file if given, and it is output if not given.

    * Treversals:
        - preorder
        - inorder
        - postoder

        - Printing in traversal:
            * a node will print the node size (the length of the strings in the node) intended by 2x depth of the node
            * followed by the list of strings from the node set (the root is considered level 0)


    Standards related requirements:
        * Have the following functions/methods minimum (the types and arguments are up to you, the names are required as given)
            - buildTree()
            - printInorder()
            - printPreorder()
            - printPostorder()

        * These must be in one file called tree.c or appropriately based on your language,
        * tree.h or as appropriate for your language
        * Define the node type in node.h
        * Keep the main function in a separate file (regardless of language)



    ##############################
    # Program Operating EXAMPLES #
    ##############################

    invocation: > P0 xxx
    Output files: xxx.inorder xxx.preorder xxx.postorder
    Invocation: > P0 < xxx.sp2020 // or > P0, followed by typing the data followed by EOF
    Output files: ouput.inorder output.preorder output.postorder


    ##############################
    #####    Traversals      #####
    ##############################
    From the 3130 textbook:

        Preorder:
            * process root
            * process children left to right

       Inorder:
            * process left child
            * process root
            * proccess right child

        Postorder:
            * process children left to right
            * process root

    ##############################
    #       More suggestions    #
    ##############################

        Functions:
            Using top-down decomposition you have 3 tasks in main:
                (i) Process command arguments

                (ii) set up file to work regardless of source
                    - Check if file readable,
                    - Set the basename for the output file, etc.

                (iii) Build the tree
                    - Traverse the tree three different ways generating outputs


            The main function should handle the 3 functionalities.
                - (i) should be handled inside of main.
                - Functions for (ii) and (iii) should be in another separate source as indicated.

            Any node types should be defined in a separate header file.

            For development purposes:
                * Do either 1 or 2 first.
                * 3 should follow 2, first with one traversal only.

        Input:
            Processing either keyboard or file input can be done one of these two ways:
                * If keyboard input:
                    - read the input into temporary file
                    - after which the rest of the program always processes file input

                * If keyboard input:
                    - set file pointer to stdin
                    - otherwise set file pointer to the actual file
                    - then process always from the file pointer

        Files:
            * node.h
            * tree.h
            * tree.c
            * main.c
            * makefile


    ###############################
    # Sample structure for main.c #
    ###############################

                #include "node.h"
                #include "tree.h"
                int main(int argc, char* argv[]) {
                  // process command line arguments first and error if improper
                  // if filename given, make sure file is readable, error otherwise
                  // set up keyboard processing so that below this point there is only one version of the code

                    node_t *root = buildTree(file);
                    printPreorder(root);
                    printInorder(root);
                    printPostorder(root);
                    return 0;
                }


    #############################################
    # Ideas for printing tree with indentations #
    #############################################

                static void printPreorder(nodeType *rootP,int level) {
                    if (rootP==NULL) return;

                    printf("%*c%d:%-9s ",level*2,' ',level,NodeId.info); // assume some info printed as string
                    printf("\n");

                    printPreorder(rootP->left,level+1);
                    printPreorder(rootP->right,level+1);
                }


    ###########
    # Testing #
    ###########
    This section is non-exhaustive testing of P0

        Create test files:
            - P0_test1.sp2020 containing empty file
            - P0_test2.2020 containing one string: adam
            - P0_test3.sp2020 containing some strings with same length (some repeats) and different length over multiple lines, e.g., use the example from above

        For each test file:
            - draw by hand the tree that should be generated. For example, using P0_test2.sp2020 should create just one node printing:  4 adam
            - Decide on invocations and what should happen:
                * what should be output filenames if no error
                * what the output files should look like (using the hand drawn trees for each file)

        Run the invocations and check against predictions
            * P0 < P0_test1
                Error

            * P0 < P0_test3.sp2020
                Outputs output.inorder output.preorder output.postorder
                - each containing the stings (no repetitions)

            * P0 P0_test3
                Outputs P0_test3.inorder P0_test3.preorder P0_test3.postorder
                - containing as above
#########################################################################################################################################################################
*/
