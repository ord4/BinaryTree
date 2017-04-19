#ifndef TREENODE_HPP
#define TREENODE_HPP
/*
    Orion Davis (3003072) ord4@zips.uakron.edu 
    The University of Akron, Computer Science II, Prof Will
    ASSGN8 Binary Tree Search
*/
// forward declaration of class Tree
template<typename NODETYPE> class Tree;

// TreeNode class-template definition
template<typename NODETYPE>
class TreeNode{
    friend class Tree<NODETYPE>;

public:
   // Constructor
   TreeNode(const NODETYPE& d){
       data = d;
   }

   NODETYPE getData() const{
       return data;
   }

   // return a leftPtr
   TreeNode* getLeftPtr() const {
      return leftPtr;
   }

   // return a rightPtr
   TreeNode* getRightPtr() const {
      return rightPtr;
   }

   // set value for leftPtr
   void setLeftPtr(TreeNode* ptr) {
      leftPtr = ptr;
   }

   // set value for rightPtr
   void setRightPtr(TreeNode* ptr) {
      rightPtr = ptr;
   }
   
private:
   NODETYPE data;
   TreeNode<NODETYPE>* leftPtr{nullptr}; // pointer to left subtree
   TreeNode<NODETYPE>* rightPtr{nullptr}; // pointer to right subtree
};

#endif // TREENODE_HPP
