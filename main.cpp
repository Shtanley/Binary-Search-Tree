//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "bst.hpp"
using namespace std;
using namespace ENSC251_Lab3;

int main() {
  BinarySearchTree* bst1 = new BinarySearchTree();
  NodePtr node = (NodePtr)malloc(sizeof(NodePtr));
  node = bst1->getRoot();
  bst1->insertNode(10);
  bst1->insertNode(5);
  bst1->insertNode(15);
  bst1->insertNode(3);
  bst1->insertNode(7);
  bst1->insertNode(13);
  bst1->insertNode(18);
  bst1->insertNode(4);
  bst1->deleteNode(4);

  //BinarySearchTree* bst2 = new BinarySearchTree();

  
  BinarySearchTree* bst3 = new BinarySearchTree();
  NodePtr node2 = (NodePtr)malloc(sizeof(NodePtr));
  node2 = bst3->getRoot();

  int ch;
  int key;
  do {
		cout << "\n\n *** Menu ***";
		cout << "\n 1. Search key";
		cout << "\n 2. Insert key";
		cout << "\n 3. Delete key";
		cout << "\n 4. Print BST";
		cout << "\n 5. Exit";

		cout << "\n\n Enter your choice: ";                        
		cin >> ch;
		
		switch (ch){
			case 1:
      cout << "Enter Key you wish to search: ";
      cin >> key;
			bst3->searchNode(key);
			break;
			case 2:
      cout << "Enter Key you wish to insert: ";
      cin >> key;
			bst3->insertNode(key);
      if(bst3->insertNode(key) == true) {return bst3->printTree()}
			break;
			case 3:
      cout << "Enter Key you wish to delete: ";
      cin >> key;
			bst3->deleteNode(key);
      if(bst3->deleteNode(key) == true) {return bst3->printTree()}
			break;
			case 4:
			bst3->printTree();
			break;
			case 5:
			exit(0);
			break;
			default: cout << "\n\t Invalid Option!";
		}
	}while (1);

  return 0;
}