#ifndef BST_H
#define BST_H

class BST{

    private:
        struct node{
            
            int key;
            node* left;
            node* right;

        };

        node* root;
        node* ReturnNodePrivate(int key, node* Ptr);

        void AddLeafPrivate(int addData, node* Ptr);
        void PrintInOrderPrivate(node* Ptr);
        
        int FindSmallestPrivate(node* Ptr);
        void RemoveNodePrivate(int key, node* parent);

    public:
        BST();
        node* CreateLeaf(int addData);
        node* ReturnNode(int key);

        void AddLeaf(int addData);
        void PrintInOrder();
        void PrintChild(int key);

        int ReturnRootKey();
        int FindSmallest(); //returns smallest node

        void RemoveNode(int key);
        void RemoveMatch();


};

#endif