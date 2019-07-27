/*
 * main.cpp
 *
 *  Created on: May 21, 2017
 *      Author: jack
 */
#include <iostream>
#include "genBST.h"

using namespace std;

int main()
{
    cout << "Binary Search Tree\n\n";
    
    BST<int> my_bst = BST<int>();
    
    my_bst.insert(13);
    my_bst.insert(10);
    my_bst.insert(25);
    my_bst.insert(2);
    my_bst.insert(12);
    my_bst.insert(20);
    my_bst.insert(31);
    my_bst.insert(29);
    
    cout << "Preoreder Traversal" << endl;
    my_bst.preorder();
    cout << "\n\n";
    
    cout << "Inorder Traversal" << endl;
    my_bst.inorder();
    cout << "\n\n";
    
    cout << "Postorder Traversal" << endl;
    my_bst.postorder();
    cout << "\n\n";
    
    return 0;
}
