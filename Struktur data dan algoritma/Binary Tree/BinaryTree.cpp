#include <iostream>
#include <string>
#include "Head.h"

using namespace std;

void BinaryTree::insert(int insertId){
	root = insertRecursive(root,insertId);
	
}
Node *BinaryTree::insertRecursive(Node *currentRoot,int insertId){
	
	if (currentRoot == NULL){
		currentRoot = new Node();
		currentRoot->id = insertId;
		return currentRoot;
	}
	if (insertId < currentRoot ->id){
		currentRoot->left = insertRecursive(currentRoot->left, insertId);
	}
	else if (insertId >  currentRoot->id){
		currentRoot->right = insertRecursive(currentRoot->right, insertId);
		
	}
	return currentRoot;
	
}



Node* BinaryTree::searchNode(Node* node, int val){
    if(node == NULL || node->id == val){
        return node;
    }
    if(val < node->id){
        return searchNode(node->left, val);
    }
    return searchNode(node->right, val);
}

Node* BinaryTree::findMin() {
    Node* node = root;
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }

        cout << "Minimum value: " << node->id << endl;


    return node;
}

Node* BinaryTree::findMax() {
    Node* node = root;
    while (node != NULL && node->right != NULL) {
        node = node->right;
    }

        cout << "Maximum value: " << node->id << endl;


    return node;
}



Node* BinaryTree::search(int val){
    Node* result = searchNode(root, val);
    if(result == NULL){
        cout << "Node with value " << val << " not found in the tree." << endl;
    }
    else {
		cout<<"Node with value " << val << " found in the tree."; 
	}
    return result;
}
 	


void BinaryTree::inOrder(){
	inOrderRecursive(root);
}

void BinaryTree::preOrder(){
	PreOrderRecursive(root);
}

void BinaryTree::postOrder(){
	PostOrderRecursive(root);
}
void BinaryTree::inOrderRecursive(Node *currentRoot){
	if(currentRoot != NULL){
		inOrderRecursive(currentRoot->left);
		cout<<currentRoot->id<<",";
		inOrderRecursive(currentRoot->right);
	}
	
}

void BinaryTree::PreOrderRecursive(Node *currentRoot){
	if(currentRoot != NULL){
		cout<<currentRoot->id<<",";
		inOrderRecursive(currentRoot->left);
		inOrderRecursive(currentRoot->right);
	}
	
}

void BinaryTree::PostOrderRecursive(Node *currentRoot){
	if(currentRoot != NULL){
		inOrderRecursive(currentRoot->left);
		inOrderRecursive(currentRoot->right);
		cout<<currentRoot->id<<",";
	}
	
}


void BinaryTree::deleteNode(int nilai){
    root = deleteRecursive(root, nilai);
}

Node* BinaryTree::deleteRecursive(Node* currentRoot, int val){
    if (currentRoot == NULL){
        return currentRoot;
    }
    if (val < currentRoot->id){
        currentRoot->left = deleteRecursive(currentRoot->left, val);
    }
    else if (val > currentRoot->id){
        currentRoot->right = deleteRecursive(currentRoot->right, val);
    }
    else{
        if (currentRoot->left == NULL && currentRoot->right == NULL){
            delete currentRoot;
            currentRoot = NULL;
        }
        else if (currentRoot->left == NULL){
            Node* temp = currentRoot;
            currentRoot = currentRoot->right;
            delete temp;
        }
        else if (currentRoot->right == NULL){
            Node* temp = currentRoot;
            currentRoot = currentRoot->left;
            delete temp;
        }
        else{
            Node* minValueNode = findMinRecursive(currentRoot->right);
            currentRoot->id = minValueNode->id;
            currentRoot->right = deleteRecursive(currentRoot->right, minValueNode->id);
        }
    }
    return currentRoot;
}

Node* BinaryTree::findMinRecursive(Node* node){
    if (node == NULL || node->left == NULL){
        return node;
    }
    return findMinRecursive(node->left);
}

