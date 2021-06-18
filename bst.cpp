//bst.cpp to implement your class
#include "bst.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace ENSC251_Lab3;

namespace ENSC251_Lab3 {

    BinarySearchTree::BinarySearchTree() {root = NULL;}
    
    NodePtr BinarySearchTree::newNode(int K) {  //function to create new root tree
        NodePtr temp;
        temp = (NodePtr)malloc(sizeof(NodePtr));
        temp->parent = NULL;
        temp->key = K;
        temp->left = temp->right = NULL;
        cout << temp->key << endl;
        return temp;
    }
    
    NodePtr BinarySearchTree::getRoot() {return root;}  //gets root
    
    NodePtr BinarySearchTree::searchNode(NodePtr current, int key) {     //search function to find node with given key
        if(current == NULL) {
            cout << "Key not found.\n";
            return NULL;
        }
        else {
            if(current->key == key) {
                cout << "Key found: " << current->key << endl;
                return current;
            }
            else if(current->key < key) {
                //cout << "R\n";
                return this->searchNode(current->right, key);
            }
            else {
                //cout << "L\n";
                return this->searchNode(current->left, key);
            }
        }
    }
    NodePtr BinarySearchTree::searchNode(int key) {
        NodePtr temp;
        if(searchNode(this->getRoot(), key) != NULL) {return searchNode(this->getRoot(), key);}
        else {return NULL;}
    }

    NodePtr BinarySearchTree::minKey(NodePtr current) {
        while (current->left != NULL) {
            current = current->left;
        }
        cout << current->key << endl;
        return current;
    }
    NodePtr BinarySearchTree::maxKey(NodePtr current) {
        while (current->right != NULL) {
            current = current->right;
        }
        cout << current->key << endl;
        return current;
    }
    NodePtr BinarySearchTree::searchSuccessor(NodePtr current, int key) {
        if(current == NULL || current->key == this->maxKey(current)->key) {
            cout << "No successor node for given key.\n";
            return NULL;
        }
        //cout << "R_key: " << current->key << endl;
        if(current->right != NULL) {    //if right node isn't NULL, the smallest key in the right tree is the successor
            //cout << "right not null\n";
            return this->minKey(current->right);
        }
        else {  //if right node is NULL, the successor lies in its ancestor
            //cout << "right null\n";
            //cout << current->parent->key << endl;
            return this->searchSuccessor(current->parent, key);
        }
        cout << "John Cena\n";
    }
    NodePtr BinarySearchTree::searchSuccessor(int key) {
        NodePtr temp;
        if(searchSuccessor(this->searchNode(key), key) != NULL) {return searchSuccessor(this->searchNode(key), key);}
        else {return NULL;}
    }

    NodePtr BinarySearchTree::insertNode(NodePtr current, int key) {    //recursive function to insert a new node
        if(root == NULL) {  //this is where the function inserts the new node
            NodePtr temp;
            root = this->newNode(key);
            temp = root;
            return root;
        }
        if(current == NULL) {
            current = this->newNode(key);
            return current;
        }

        else {  //traverse the tree, includes debug statements
            if(current->key == key) {
                cout << "Failed to insert duplicate node.\n";
                return NULL;
            }
            else if(current->key < key) {
                    current->right = this->insertNode(current->right, key);
                    current->right->parent = current;
                    //cout << "R: " << current->right->parent->key << endl;
                    return current;
            }
            else {
                    current->left = this->insertNode(current->left, key);
                    current->left->parent = current;
                    //cout << "L: " << current->left->parent->key << endl;
                    return current;
            }
        }
    }
    bool BinarySearchTree::insertNode(int key) 
    {
        if(insertNode(this->getRoot(), key) != NULL) {return true;}
        else {return false;}
    }

    NodePtr BinarySearchTree::deleteNode(NodePtr current, int key) {
        NodePtr temp = (NodePtr)malloc(sizeof(NodePtr));
        if(current == NULL) {
            cout << "Node doesn't exsist in the current BST.\n";
            return current;
        }
        if(current->key > key) {
            current->left = deleteNode(current->left, key);
            cout << "Left\n";
        }
        else if(current->key < key) {
            current->right = deleteNode(current->right, key);
            cout << "Right\n";
        }
        else {
            if (current->left == NULL && current->right == NULL) {  //0 children
                free(current);
                cout << "Node deleted.\n";
                current = NULL;
            }
            //1 child
            else if(current->right == NULL) {
                temp = current;
                current = current->left;
                free(temp);
                cout << "Node with 1 child deleted.\n";
            }
            else if(current->left == NULL) {
                temp = current;
                current = current->right;
                free(temp);
                cout << "Node with 1 child deleted.\n";
            }
            else {  //2 children
                temp = searchSuccessor(current, key);
                current->key = temp->key;
                free(temp);
                cout << "Node with 2 children deleted.\n";
            }
        }
        return current;
    }
    bool BinarySearchTree::deleteNode(int key) {
        if(deleteNode(this->getRoot(), key) != NULL) {return true;}
        else {return false;}
    }
/*
    ostream& operator <<(ostream& out, const BinarySearchTree& objects) {
        int h = this->height(this->getRoot());
        //cout << "Height: " << h << endl;
        for(int i = 1; i <= h; i++) {
            this->printLvl(this->getRoot(), i);
            out << "\n";
            return out;
        }
    }*/

    void BinarySearchTree::printTree() {    //Print whole tree
        int h = this->height(this->getRoot());
        //cout << "Height: " << h << endl;
        for(int i = 1; i <= h; i++) {
            this->printLvl(this->getRoot(), i);
            cout << "\n";
        }
    }
    void BinarySearchTree::printLvl(NodePtr node, int lvl) {    //Print nodes at given level
        if(node == NULL) {return;} 
        if(lvl == 1) {
            cout << node->key << " ";
        }  
        else if(lvl > 1)  
        {  
            printLvl(node->left, lvl-1);
            printLvl(node->right, lvl-1);  
        }
    }
    int BinarySearchTree::height(NodePtr node) {    //Compute the height/levels of the tree
        if(node == NULL) {return 0;}
        else {
            //compute the height of each subtree
            int Lheight = height(node->left);  
            int Rheight = height(node->right);
            //and use the larger one
            if (Lheight > Rheight) {return(Lheight += 1);}
        else {return(Rheight += 1);}
        }
    }
/*
    BinarySearchTree::BinarySearchTree(const BinarySearchTree& node) {
        this->copy(this->getRoot(), this->getRoot());
    }*/
    void BinarySearchTree::copy(NodePtr node1, NodePtr node2) {
        if(node1 == NULL) {node2 = NULL;}
        else {
            if(node1->left) {
                NodePtr newL = (NodePtr)malloc(sizeof(NodePtr));
                newL->parent = node2;
                node2->left = newL;
                copy(node1->left, node2->left);
            }
            if(node1->right) {
                NodePtr newR = (NodePtr)malloc(sizeof(NodePtr));
                newR->parent = node2;
                node2->right = newR;
                copy(node1->right, node2->right);
            }
        }
    }
/*
    BinarySearchTree& BinarySearchTree::operator =(const BinarySearchTree &bst) {
        
    }*/

}
