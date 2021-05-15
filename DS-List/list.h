#ifndef LIST_H
#define LIST_H

class List{

    private:
        
        struct node{

            int data;
            node* next;

        };

        node* head;
        node* curr;
        node* temp;
        
        node* SearchNodePrivate(int searchData, node* Ptr);

    public:
        List();
        void AddNode(int addData);
        node* SearchNode(int searchData);
        void DeleteNode(int deleteData);
        void PrintNode();
        void InsertNode(int insertData, int place);


};

#endif