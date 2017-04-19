#ifndef TREE_HPP
#define TREE_HPP
/*
    Orion Davis (3003072) ord4@zips.uakron.edu 
    The University of Akron, Computer Science II, Prof Will
    ASSGN8 Binary Tree Search
*/
#include <iostream>
#include "treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth(TreeNode<NODETYPE>* ptr) const {
       int rightDepth, leftDepth;
      if(ptr->leftPtr == nullptr && ptr->rightPtr == nullptr){
           //There are no leaves to this node
           return 0;
       }
       else{
           leftDepth = getDepth(ptr->leftPtr);
           rightDepth = getDepth(ptr->rightPtr);
           if(leftDepth < rightDepth){
               return rightDepth;
           }
           else{
               return leftDepth;
           }
       }
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
      return binarySearchHelper(rootPtr, val);
   }

   TreeNode<NODETYPE>* getRoot(){
       return rootPtr;
   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   /*int determineDepth(TreeNode<NODETYPE>* root, int* leftDepth, int* rightDepth) const{
       if(root->leftPtr == nullptr && root->rightPtr == nullptr){
           //There are no leaves to this node
           return 0;
       }
       else{
           int leftDepth = determineDepth(root->leftPtr, leftDepth, rightDepth);
           int rightDepth = determineDepth(root->rightPtr, leftDepth, rightDepth);
           if(leftDepth < rightDepth){
               return rightDepth;
           }
           else{
               return leftDepth;
           }
       }
   }*/

   // do a binary search on the Tree
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* ptr, int value) const{
       if(ptr == nullptr){
           // Empty list/end of tree
           return nullptr;
       }
       else if(value < ptr->getData()){
           // Value is on the left side of the tree
           std::cout << "Comparing " << value << " to " << ptr->getData() << ": ";
           std::cout << "smaller, walk left\n";
           return binarySearchHelper(ptr->leftPtr, value);
       }
       else if(value > ptr->getData()){
           // Value is on the right side of the tree
           std::cout << "Comparing " << value << " to " << ptr->getData() << ": ";
           std::cout << "larger, walk right\n";
           return binarySearchHelper(ptr->rightPtr, value);
       }
       else{
           // Value has been found
           std::cout << "Comparing " << value << " to " << ptr->getData() << ": ";
           std::cout << "search complete\n";
           return ptr;
       }
   }
   
   
};

#endif // TREE_HPP
