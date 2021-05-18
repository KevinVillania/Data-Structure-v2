#include <iostream>
#include "BSTPractice.h"
using namespace std;

BST2::BST2(): root(nullptr){

    //ctor
}

BST2::node* BST2::CreateLeaf(int key){

    node* n1 = new node;

    n1->key = key;
    n1->left = nullptr;
    n1->right = nullptr;

    return n1;
}

void BST2::AddLeaf(int key){

    AddLeafPrivate(key, root);
}

void BST2::AddLeafPrivate(int key, node* Ptr){

    if(root == nullptr){

        root = CreateLeaf(key);

    }else if(key > Ptr->key){

        if(Ptr->right != nullptr){

            AddLeafPrivate(key, Ptr->right);
        }else{

            Ptr->right = CreateLeaf(key);
        }
    }else if(key < Ptr->key){

        if(Ptr->left != nullptr){

            AddLeafPrivate(key, Ptr->left);
        }else{

            Ptr->left = CreateLeaf(key);
        }
    }else{

        cout << key << " is already in the tree";
    }
}

void BST2::PrintInOrder(){

    PrintInOrderPrivate(root);
}

void BST2::PrintInOrderPrivate(node* Ptr){

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

BST2::node* BST2::ReturnNode(int key){

    return ReturnNodePrivate(key,root);
}

BST2::node* BST2::ReturnNodePrivate(int key, node* Ptr){

    if(Ptr != nullptr){

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

void BST2::PrintChild(int key){

    node* Ptr = ReturnNode(key);

    if(Ptr != nullptr){

        cout << "Parent node: " << Ptr->key << endl;

        Ptr->left == nullptr ? cout << "Left child: null\n" : cout << "Left child: " << Ptr->left->key << endl;
        Ptr->right == nullptr ? cout << "Left child: null\n" : cout << "Right child: " << Ptr->right->key << endl; 

    }else{

        cout << key << " doesn't exist\n";
    }
}

int BST2::FindSmallest(){

    return FindSmallestPrivate(root);
}

int BST2::FindSmallestPrivate(node* Ptr){

    if(root != nullptr){

        if(Ptr->left != nullptr){

            return FindSmallestPrivate(Ptr->left);
        }

        return Ptr->key;

    }else{

        return -404;
    }
}