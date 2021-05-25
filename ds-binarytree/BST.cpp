#include <iostream>
#include "BST.h"
using namespace std;

BST::BST(): root(nullptr){

    //initializing root to null
}

BST::node* BST::CreateLeaf(int addData){

    node* n1 = new node;

    n1->key = addData;
    n1->left = nullptr;
    n1->right = nullptr;

    return n1;
}

void BST::AddLeaf(int addData){

    AddLeafPrivate(addData, root);
}

void BST::AddLeafPrivate(int addData, node* Ptr){

    //check if walang laman ang tree
    if(root == nullptr){

        root = CreateLeaf(addData);
    }else if(addData > Ptr->key){

        //we want to check if we are at the end of tree
        if(Ptr->right != nullptr){

            AddLeafPrivate(addData, Ptr->right); //recursively calls function but now starting on Ptr->right
        }else{

            Ptr->right = CreateLeaf(addData); //create a leaf on the Ptr->right
        }
    }else if(addData < Ptr->key){

        //we want to check if we are at the end of tree
        if(Ptr->left != nullptr){

            AddLeafPrivate(addData, Ptr->left); //recursively calls the function but now starting on Ptr->left
        }else{

            Ptr->left = CreateLeaf(addData); //create a leaf on the Ptr->left
        }
    }else{

        cout << addData << " is already in the tree\n";
    }
}

BST::node* BST::ReturnNode(int key){

    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr){

    if(Ptr != nullptr){

        //code
        if(key == Ptr->key){
            
            return Ptr;
        }else{
            if(key > Ptr->key){

                return ReturnNodePrivate(key, Ptr->right);
            }
            if(key < Ptr->key){

                return ReturnNodePrivate(key, Ptr->left);
            }
        }

    }else{

        return nullptr;
    }
}

void BST::PrintInOrder(){

    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr){

    if(root != nullptr){

        if(Ptr->left != nullptr){

            PrintInOrderPrivate(Ptr->left);
        }

        cout << Ptr->key << " ";

        if(Ptr->right != nullptr){

            PrintInOrderPrivate(Ptr->right);
        }

    }else{

        cout << "Tree is empty\n";
    }
}

//Returns root
int BST::ReturnRootKey(){

    if(root != nullptr ){
        
        //if may laman ang root
        return root->key;
    }else{

        return -404;
    }
}

//Prints parent and child nodes
void BST::PrintChild(int key){

    //Create a pointer that points to the address of key
    node* Ptr = ReturnNode(key);

    //check if address points to a data and not null
    if(Ptr != nullptr){

        //may laman ang Ptr
        cout << "Parent node: " << Ptr->key << endl; //parent node

        Ptr->left == nullptr ? cout << "Left child: null\n" : cout << "Left child: " << Ptr->left->key << endl; //left child

        Ptr->right == nullptr ?  cout << "Right child: null\n" : cout << "Right child: " << Ptr->right->key; //right child

    }else{

        cout << "Node doesn't exist on tree\n";
    }
}


int BST::FindSmallest(){

    return FindSmallestPrivate(root);
}

//traverses up to the far left side of tree to return smallest number
int BST::FindSmallestPrivate(node* Ptr){

    if(root == nullptr){

        return -404;
    }else{

        if(Ptr->left != nullptr){

            return FindSmallestPrivate(Ptr->left);
        }else{

            return Ptr->key;
        }
    }
}

void BST::RemoveNode(int key){

    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent){

    if(root != nullptr){

        if(key == parent->key){

            RemoveRootMatch();
        }else if(key > parent->key && parent->right != nullptr){

            key == parent->right->key ? RemoveMatch(parent, parent->right, true) : RemoveNodePrivate(key, parent->right);
            
        }else if(key < parent->key && parent->left != nullptr){

            key == parent->left->key ? RemoveMatch(parent, parent->left, true) : RemoveNodePrivate(key, parent->left);
        }else{

            cout << key << " is not in the tree\n";
        }

    }else{

        cout << "Tree is empty\n";
    }
}

//Function that re-assigns root node
void BST::RemoveRootMatch(){

    if(root != nullptr){

        node* delPtr = root; //create a new pointer and sets it to address of root
        int rootKey = root->key; //gets a copy of value of root before deletion
        int smallestNumber; 

        //DIFF CASES OF ROOT VALUE
        //Case-1 Nag-iisa lang ang root
        if(root->left == nullptr && root->right == nullptr){

            root = nullptr; //de-allocates memory
            delete delPtr;

        //Case 2 may laman left child, right child wala
        }else if(root->left != nullptr && root->right == nullptr ){

            root = root->left; //re-assign root to root->left
            delPtr->left = nullptr; //re-assign delPtr->left to nullptr
            delete delPtr; //delete delPtr;

            cout << "The root node " << rootKey << " was deleted and overwritten with " << root->key << endl;

        //Case 3 left child walang laman, right child meron
        }else if(root->left == nullptr && root->right != nullptr ){

            root = root->right;
            delPtr->right = nullptr;
            delete delPtr;

            cout << "The root node " << rootKey << " was deleted and overwritten with " << root->key << endl;

        //Case 4 both child may laman
        }else{

            smallestNumber = FindSmallestPrivate(root->right); 
            RemoveNodePrivate(smallestNumber,root);
            root->key = smallestNumber;
            delete delPtr;   
        }
    }else{

        cout << endl << "Tree is empty\n";
    }

}