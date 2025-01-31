/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    if(root==NULL){
      return;
    }
    else{
      Node* original=root;

      Node* temp=root->left;
      root->left=root->right;
      root->right=temp;

      root=root->right;
      mirror();

      root=original;

      root=root->left;
      mirror();

      root=original;
    }
}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    int flag=0;

    typename InorderTraversal<T>::InorderTraversal test(root);
    typename InorderTraversal<T>::InorderTraversal test2(root);
    typename TreeTraversal<T>::Iterator test_ = test.begin();
    typename TreeTraversal<T>::Iterator test_2=test2.begin();
    for(test_=test.begin(); test_!=test.end(); ++test_){
      ++test_2;
      Node* temp=*test_;
      Node* temp2=*test_2;
      if(temp2==NULL){
        break;
      }
      if(temp->elem > temp2->elem){
        flag=1;
      }
    }

    if(flag==0){
      return true;
    }
    return false;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here

    return orderedrecursive(root);
}

template <typename T>
bool BinaryTree<T>::orderedrecursive(Node* subRoot)const{
  if(subRoot==NULL){
    return true;
  }
  if(subRoot->left==NULL && subRoot->right==NULL){
    return true;
  }

  if(subRoot->left==NULL){
    if(subRoot->right->elem > subRoot->elem){
      return orderedrecursive(subRoot->right);
    }
    else{
      return false;
    }
  }

  if(subRoot->right==NULL){
    if(subRoot->left->elem < subRoot->elem){
    return orderedrecursive(subRoot->left);
    }
    else{
      return false;
    }
    }

  else{
  if(subRoot->right->elem < subRoot->elem){
    return false;
  }
  if(subRoot->left->elem > subRoot->elem){
    return false;
  }
  bool temp=orderedrecursive(subRoot->left);
  bool temp2=orderedrecursive(subRoot->right);
  return(temp && temp2);
  }
}


/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::getPaths(vector<vector<T> > &paths) const
{
    // your code here
    vector<T> map;
    mapping(paths, map, root);
}

template <typename T>
void BinaryTree<T>::mapping(vector<vector<T> > &paths, vector<T> &map, Node* subRoot) const{
  if(subRoot==NULL){
    return;
  }
  if(subRoot->left==NULL && subRoot->right==NULL){
    map.push_back(subRoot->elem);
    paths.push_back(map);
    map.pop_back();
    return;
  }
  map.push_back(subRoot->elem);
  mapping(paths, map, subRoot->left);
  mapping(paths, map, subRoot->right);
  map.pop_back();
}


/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    int sum=0;
    return sumDistances(root, sum);

}

template <typename T>
int BinaryTree<T>::sumDistances(Node* subRoot, int sum)const{
  if(subRoot->left!=NULL && subRoot->right!=NULL){
    sum=sum+sumDistances(subRoot->left, sum+1)+sumDistances(subRoot->right, sum+1);
  }
  if(subRoot->left==NULL && subRoot->right!=NULL){
    sum=sum+sumDistances(subRoot->right, sum+1);
  }
  if(subRoot->left!=NULL && subRoot->right==NULL){
    sum=sum+sumDistances(subRoot->left, sum+1);
  }
  if(subRoot->left==NULL && subRoot->right==NULL){
  }
  return sum;
}
