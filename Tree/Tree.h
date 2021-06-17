#include <iostream>
using namespace std;

//Page 257.
template <class T> class Tree; // forward declaration

template <class T>
class TreeNode {
    friend class Tree<T>;
    private:
        T data;
        TreeNode<T> *leftChild;
        TreeNode<T> *rightChild;
        TreeNode(T data=0, TreeNode<T> *leftChild=NULL, TreeNode<T> *rightChild=NULL) { this->data = data;
            this->leftChild = leftChild;
            this->rightChild = rightChild;
        }
};

template <class T>
class Tree {
    public:
        // Tree operations
        Tree(T data = 0) {
            root = new TreeNode<T>(data);
        }
        void insert(int temp);
        void Visit(TreeNode<T> *currentNode);
        void Inorder();
        void Inorder(TreeNode<T> *currentNode);
        void Preorder();
        void Preorder(TreeNode<T> *currentNode);
        void Postorder();
        void Postorder(TreeNode<T> *currentNode);
        
        Tree(const Tree<T>& s);
        TreeNode<T>* Copy(TreeNode<T> *origNode);
        bool operator==(const Tree& t) const;
        bool Equal(TreeNode<T> *a, TreeNode<T> *b) const;

    private:
        TreeNode<T> *root;
};

template <class T>
void Tree<T>::insert(int input) {
    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;
    while (current != NULL) {
        parent = current;
        if (input < current->data) { //Data of Current > Input: Left.
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    
    if (root->data == 0)
        root = new TreeNode<T>(input); //Data of Root is Empty.
    else {
        if (input < parent->data) { //Data of Parent > Input: Left.
            parent->leftChild = new TreeNode<T>(input);
        } else if (input > parent->data) {
            parent->rightChild = new TreeNode<T>(input);
        } else {
            cout << "Same data is not accept" << endl;
            return;
        }
    }
 }

template <class T>
void Tree<T>::Visit(TreeNode<T> *currentNode) {
    cout << currentNode->data << " ";
}

//Program 5.1: Inorder traversal of a binary tree.
template <class T>
void Tree<T>::Inorder() {   // Driver calls workhorse for traversal of entire tree.
                            // The driver is declared as a public member function of Tree.
    Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T> * currentNode) {  // Workhorse traverses the subtree rooted at currentNode.
                                                    // The workhorse is declared as a private member function of Tree.
    if (currentNode) {
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}

//Program 5.2: Preorder traversal of a binary tree.
template <class T>
void Tree<T>::Preorder() {   // Driver.
    Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T> * currentNode) {  // Workhorse.
    if (currentNode) {
        Visit(currentNode);
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
    }
}

//Program 5.3: Postorder traversal of a binary tree.
template <class T>
void Tree<T>::Postorder() {   // Driver.
    Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> * currentNode) {  // Workhorse.
    if (currentNode) {
        Postorder(currentNode->leftChild);
        Postorder(currentNode->rightChild);
        Visit(currentNode);
    }
}

//Program 5.9:Copying a binary tree
template <class T>
Tree<T>::Tree(const Tree<T>& s) {   // driver
    // Copy constructor
    root = Copy(s.root);
}

template <class T>
TreeNode<T>* Tree<T>::Copy(TreeNode<T> *origNode) { // Workhorse
    // Return a pointer to an exact copy of the binary tree rooted at origNode.
    if (!origNode) return 0;
    return new TreeNode<T>(origNode->data,
                           Copy(origNode->leftChild),
                           Copy(origNode->rightChild));
}

//Program 5.10:Binary tree equivalence
template <class T>
bool Tree<T>::operator==(const Tree& t) const {
    return Equal(root, t.root);
}

template <class T>
bool Tree<T>::Equal(TreeNode<T> *a, TreeNode<T> *b) const { // Workhorse.
  if ((!a) && (!b)) return true;    // both a and b are 0
  return (a && b                    // both a and b are non-zero
          && (a->data == b->data)                   // data is the same
          && Equal(a->leftChild, b->leftChild)      // left subtrees equal
          && Equal(a->rightChild, b->rightChild));  // right subtrees equal
}
