/*
 * genBST.h
 *
 *  Created on: May 21, 2017
 *      Author: jack
 */

#include <queue>
#include <stack>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE


template<class T>
class Stack : public stack<T>
{
	// See Figure 4.21
};


template<class T>
class Queue : public queue<T>
{
public:
	T dequeue() {
		T tmp = queue<T>::front();
		queue<T>::pop();
		return tmp;
	}
	void enqueue(const T& el) {
		push(el);
	}
};


template<class T>
class BSTNode
{
public:
	BSTNode() {
		left = right = 0;
	}
	BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
		el = e; left = l; right = r;
	}

	T el;
	BSTNode<T> *left, *right;
};

template<class T>
class BST
{
public:
	BST() {
		root = 0;
	}
	
    ~BST() {
		clear();
	}
	
    void clear() {
		//clear(root); root = 0;
	}
	
    bool isEmpty() const {
		return root == 0;
	}
	
    void preorder() {				// Fig 6.11
		preorder(root);
	}
	
    void inorder() {				// Fig 6.11
		inorder(root);
	}
	
    void postorder() {				// Fig 6.11
		postorder(root);
	}
	
    T* search(const T& el) const {	// Fig 6.9
		return search(root, el);
	}

	//void breadthFirst();			// Fig 6.10
	//void iterativePreorder();		// Fig 6.15
	//void iterativeInorder();		// Fig 6.17
	//void iterativePostorder();		// Fig 6.16
	//void MorrisInorder();			// Fig 6.20
	void insert(const T&);				// Fig 6.23
	//void deleteByMerging(BSTNode<T>*&);		// Fig 6.29
	//void findAndDeleteByMerging(const T&);		// Fig 6.29
	//void deleteByCopying(BSTNode<T>*&);		// Fig 6.32
	//void balance(T*,int,int);		// Fig 6.7

protected:
	BSTNode<T>* root;

	//void clear(BSTNode<T>*);
	T* search(BSTNode<T>*, const T&) const; // Fig 6.9
	void preorder(BSTNode<T>*);				// Fig 6.11
	void inorder(BSTNode<T>*);				// Fig 6.11
	void postorder(BSTNode<T>*); 			// Fig 6.11
	virtual void visit(BSTNode<T>* p) {
        cout << p->el << ' ';
	}
};

template<class T>
void BST<T>::insert(const T& el) {
    BSTNode<T> *p    = root;    // pointer to tree root
    BSTNode<T> *prev = 0;       // pointer to previous node
                                // as we traverse the tree
    
    // traverse tree until reaching a leaf (node with no children)
    while (p != 0) {
        prev = p;
        
        if (el < p->el)
            p = p->left;
        else // el > p->el
            p = p->right;
    }
    
    if (0 == root)
        root = new BSTNode<T>(el);
    else if (el < prev->el)
        prev->left = new BSTNode<T>(el);
    else // el > prev->el
        prev->right = new BSTNode<T>(el);
}

template<class T>
void BST<T>::preorder(BSTNode<T> *p) {  // VLR
    if (p !=0) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::inorder(BSTNode<T> *p) {  // LVR
    if (p !=0) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T> *p) {  // LRV
    if (p !=0) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template<class T>
T* BST<T>::search(BSTNode<T> *p, const T& el) const {  // Input: root, el_to_search_for
    
    while (0 != p) {
        if (el == p->el)
            return &p->el;  // Found it
        else if (el < p->el)
            p = p->left;
        else // el > p->val
            p = p->right;
    }
    
    return 0; // not found
}


#endif /* BINARY_SEARCH_TREE */
