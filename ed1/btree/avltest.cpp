#include <iostream>
#include "avltree.h"
using namespace std;

int main()
{
    // Create an AVLTree object
    AVLTree<int> avlTree;

    // Insert some values into the AVL tree
    avlTree.insert(10, 10);
    avlTree.insert(5, 5);
    avlTree.insert(15, 15);

    // Print the size of the tree
    cout << "Size of the AVL Tree: " << avlTree.size() << endl;

    // Perform inorder walk
    avlTree.walk();
    // Perform some searches
    int searchKey = 5;
    auto searchResult = avlTree.search(searchKey);

    if (searchResult.second)
    {
        cout << "Key " << searchKey << " found. Data: " << searchResult.first << endl;
    }
    else
    {
        cout << "Key " << searchKey << " not found." << endl;
    }

    // Add more testing scenarios (insertions, deletions, searches) as needed
    avlTree.remove(5);

    cout << "Size of the AVL Tree: " << avlTree.size() << endl;

    // Perform inorder walk
    avlTree.walk();

    avlTree.insert(20, 20);
    cout << "Size of the AVL Tree: " << avlTree.size() << endl;
    // Perform inorder walk
    avlTree.walk();

    // Remove Mos recently inserted node
    avlTree.remove(20);

    cout << "Size of the AVL Tree: " << avlTree.size() << endl;

    avlTree.insert(13, 13);

    // Perform inorder walk
    avlTree.walk();

    avlTree.remove(13);
    avlTree.remove(15);
    cout << "Size of the AVL Tree: " << avlTree.size() << endl;

    avlTree.insert(7, 7);
    avlTree.insert(5, 7);
    cout << "Size of the AVL Tree: " << avlTree.size() << endl;

    // Perform inorder walk
    avlTree.walk();


    avlTree.remove(5);
    cout << "Size of the AVL Tree: " << avlTree.size() << endl;

    avlTree.insert(8, 8);

    // Perform inorder walk
    avlTree.walk();

    cout << "Everything is in working order!" << endl;

    return 0;
}