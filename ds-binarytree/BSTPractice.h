#ifndef BSTPRACTICE_H
#define BSTPRACTICE_H

//CreateLeaf
//AddLeaf
//PrintInOrder
//ReturnNode
//PrintChildren
//FindSmallest

class BST2{

    private:
        struct node{

            int key;
            node* left;
            node* right;

        };

        node* root;

        void AddLeafPrivate(int key, node* Ptr);
        void PrintInOrderPrivate(node* Ptr);
        node* ReturnNodePrivate(int key, node* Ptr);
        int FindSmallestPrivate(node* Ptr);


    public:
        BST2();
        node* CreateLeaf(int key);
        void AddLeaf(int key);
        void PrintInOrder();
        node* ReturnNode(int key);
        void PrintChild(int key);
        int FindSmallest();

};

#endif 