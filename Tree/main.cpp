#include <iostream>
#include "Tree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Tree<int> tree;
    
    //insert().
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    
    //'==' Operation.
    //Copy Constructor.
    Tree<int> tree_(tree);
    bool check = (tree == tree_);
    cout << "tree == tree_: " << check << endl;
        
    //Inorder();
    cout << "Inorder: ";
    tree.Inorder();
    cout << endl;
    
    //Preorder();
    cout << "Preorder: ";
    tree.Preorder();
    cout << endl;
    
    //Postorder();
    cout << "Postsorder: ";
    tree.Postorder();
    
    return 0;
}
