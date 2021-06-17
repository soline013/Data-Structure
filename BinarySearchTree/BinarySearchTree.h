#include <iostream>
using namespace std;

template <class T>
class TreeNode {
    //friend class Tree<T>;
    public:
        T data;
        TreeNode<T>* leftChild;
        TreeNode<T>* rightChild;
        int leftSize;
        TreeNode() {}
        TreeNode(T n) {
            data = n;
            leftChild = NULL;
            rightChild = NULL;
        }
        TreeNode(T n, TreeNode<T>* left, TreeNode<T>* right) {
            data = n;
            leftChild = left;
            rightChild = right;
        }
};

// ADT 5.3:A dictionary
template <class K, class E>
class BST {
    private:
        TreeNode<pair<K, E>> *root;
    
    public:
        BST() {
            root = 0;
        }
        bool IsEmpty() const;           // return true iff the dictionary is empty
        pair<K,E>* Get(const K& k); // return pointer to the pair with specified key; return 0 if no such pair
        pair<K,E>* Get(TreeNode<pair<K,E> >* p, const K& k);
        void Insert(const pair<K,E>&);  // insert the given pair; if key is a duplicate update associated element
        pair<K,E>* RankGet(int r);
        void Split(const K& k, BST<K,E>& small, pair<K,E>*& mid, BST<K,E>& big);
        void Delete(const K& k);          // delete pair with specified key
        TreeNode<pair<K, E>>* Delete(TreeNode<pair<K, E>>* node, const K& k);
 };

template <class K, class E>
bool BST<K,E>::IsEmpty() const {
    return root == NULL;
}

// Program 5.18:Recursive search of a binary search tree
//순환적 탐색
template <class K, class E>             // Driver
pair<K,E>* BST<K,E>::Get(const K& k) {  // Search the binary search tree (*this) for a pair with key k.
    // If such a pair is found, return a pointer to this pair; otherwise, return 0.
    return Get(root, k);
}

template <class K, class E>  // Workhorse
pair<K,E>* BST<K,E>::Get(TreeNode<pair<K,E> >* p, const K& k) {
    if (!p) return 0;
    if (k < p->data.first) return Get(p->leftChild,k);
    if (k > p->data.first) return Get(p->rightChild,k);
    return &p->data;
}

// Program 5.19:Iterative search of a binary search tree
//반복적 탐색.
/*
template <class K, class E>  // Iterative version
pair<K,E>* BST<K,E>::Get(const K& k) {
    TreeNode<pair<K,E> > *currentNode = root;
    while (currentNode) {
        if (k < currentNode->data.first)
            currentNode = currentNode->leftChild;
        else if (k > currentNode->data.first)
            currentNode = currentNode->rightChild;
        else return &currentNode->data;
    }
   
    // no matching pair
    return 0;
}
*/
 
// Program 5.20:Searching a binary search tree by rank
template <class K, class E>             // search by rank
pair<K,E>* BST<K,E>::RankGet(int r) { // Search the binary search tree for the rth smallest pair.
    TreeNode<pair<K,E> > *currentNode = root;
    while (currentNode)
        if (r < currentNode->leftSize)
            currentNode = currentNode->leftChild;
        else if (r > currentNode->leftSize) {
            r -= currentNode->leftSize;
            currentNode = currentNode->rightChild;
        }
        else return &currentNode->data;
    
    return 0;
}

// Program 5.21:Insertion into a binary search tree
template <class K, class E>
void BST<K,E>::Insert(const pair<K,E>& thePair) { // Insert thePair into the binary search tree.
    // search for thePair.first, pp is parent of p
    TreeNode<pair<K,E> > *p = root, *pp = 0;
    while (p) {
       pp = p;
       if (thePair.first < p->data.first) p = p->leftChild;
       else if (thePair.first > p->data.first) p = p->rightChild;
       else { // duplicate, update associated element
           p->data.second = thePair.second;
           return;
       }
    }

    // perform insertion
    p = new TreeNode<pair<K,E> > (thePair);
    if (root) // tree not empty
       if (thePair.first < pp->data.first) pp->leftChild = p;
       else pp->rightChild = p;
    else root = p;
}

// Program 5.22:Splitting a binary search tree
template <class K, class E>
void BST<K,E>::Split(const K& k, BST<K,E>& small, pair<K,E>*& mid, BST<K,E>& big) { // Split the binary search tree with respect to key k.
    if (!root) {small.root = big.root = 0; return;} // empty tree
    
    // create header nodes for small and big
    TreeNode<pair<K,E> > *sHead = new TreeNode<pair<K,E> >,
                         *s = sHead,
                         *bHead = new TreeNode<pair<K,E> >,
                        *b = bHead,
                         *currentNode = root;
    
    while (currentNode)
        if (k < currentNode->data.first) { // add to big
            b->leftChild = currentNode;
            b = currentNode; currentNode = currentNode->leftChild;
       } else if (k > currentNode->data.first) { // add to small
           s->rightChild = currentNode;
           s = currentNode; currentNode = currentNode->rightChild;
       } else { // split at currentNode
           s->rightChild = currentNode->leftChild;
           b->leftChild = currentNode->rightChild;
           small.root = sHead->rightChild; delete sHead;
           big.root = bHead->leftChild; delete bHead;
           mid = new pair<K,E>(currentNode->data.first, currentNode->data.second);
           delete currentNode;
           return;
       }
    
    // no pair with key k
    s->rightChild = b->leftChild = 0;
    small.root = sHead->rightChild; delete sHead;
    big.root = bHead->leftChild; delete bHead;
    mid = 0;
    return;
}

template <class K, class E>
void BST<K,E>::Delete(const K& k) {
    root = Delete(root, k);
}

template <class K, class E>
TreeNode<pair<K, E>>* BST<K,E>::Delete(TreeNode<pair<K, E>>* node, const K& k) {
    if (node == NULL) {
        return NULL;
    } else if (k > node->data.first) {
        node->rightChild = Delete(node->rightChild, k);
    } else if (k < node->data.first) {
        node->leftChild = Delete(node->leftChild, k);
    } else {
        if (node->leftChild == NULL && node->rightChild == NULL) {
            node = NULL;
            return node;
        } else if (node->leftChild == NULL) {
            node = node->rightChild;
            return node;
        } else if (node->rightChild == NULL) {
            node = node->leftChild;
            return node;
        } else {
            TreeNode<pair<K, E>>* remove; remove = node->rightChild;
            while (remove->leftChild != NULL) {
                remove = remove->leftChild;
            }
            int minVal1 = remove->data.first;
            int minVal2 = remove->data.second;
            node = Delete(node, minVal1);
            node->data.first = minVal1;
            node->data.second = minVal2;
            return node;
        }
    }
    return NULL;
}
