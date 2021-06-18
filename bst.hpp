//header file bst.hpp to declare your class
#ifndef BST_HPP
#define BST_HPP

namespace ENSC251_Lab3 {
  
  struct Node {
    int key; // key value of the node
    struct Node *parent; // pointer to parent node
    struct Node *left; // pointer to left subtree
    struct Node *right; // pointer to right subtree
  };
  typedef struct Node* NodePtr;
  
  class BinarySearchTree {
    public:
    BinarySearchTree(); //default construtor
    NodePtr getRoot();  //gets private member root

    //~BinarySearchTree();  //default destructor
    //BinarySearchTree(int key);
    //BinarySearchTree(const BinarySearchTree& node); //copy constructor
    void copy(NodePtr node1, NodePtr node2);
    //friend ostream& operator <<(ostream& out, const BinarySearchTree& node);
    //BinarySearchTree& operator =(const BinarySearchTree &bst);

    NodePtr newNode(int key);
    NodePtr searchNode(NodePtr node, int key);
    NodePtr searchNode(int key);
    NodePtr minKey(NodePtr node);
    NodePtr maxKey(NodePtr node);
    NodePtr searchSuccessor(NodePtr node, int key);
    NodePtr searchSuccessor(int key);

    NodePtr insertNode(NodePtr node, int key);
    bool insertNode(int key);
    
    NodePtr deleteNode(NodePtr node, int key);
    bool deleteNode(int key);

    void printTree();
    void printLvl(NodePtr node, int lvl);
    int height(NodePtr node);

    private:
    NodePtr root;
  };
}
#endif