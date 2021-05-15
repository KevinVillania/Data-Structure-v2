#include <iostream>
#include "list.h"
using namespace std;

List::List():head(nullptr),curr(nullptr),temp(nullptr){

    //constructor initialize pointers to nullptr
}


void List::AddNode(int addData){

    node* n1 = new node; //memory allocation

    n1->data = addData; //arrow pointer is used when pointer needs to access variables inside struct 
    n1->next = nullptr;

    //if may laman ang list
    if(head != nullptr){

        curr = head; //initialize curr pointer at the start of LL (head)
        while(curr->next != nullptr){
            
            //traverses thru the list
            curr = curr->next;
        }

        curr->next = n1;

    }else{

        //if walang laman ang list
        head = n1;
    }
}

List::node* List::SearchNodePrivate(int searchData, node* Ptr){

     if(head != nullptr){

        //may laman ang list
        curr = head;
        
        /*
        Traverses LL while checking for the searchData
        while (True && True)
        */
        while(curr != nullptr && curr->data != searchData){

            curr = curr->next;
        }

        //checks for values of curr
        if(curr == nullptr){

            //if wala sa list
            return nullptr; 

        }
        if(searchData == curr->data){

            cout << searchData << " found at ";
            return curr;    
        }

    }else{

        return nullptr;
    }
}


List::node* List::SearchNode(int searchData){

   return SearchNodePrivate(searchData, head);
}


void List::DeleteNode(int deleteData){

    //initializes a temporary storage pointer
    node* delPtr = nullptr;

    //initializes curr and temp pointers to head
    curr = head;
    temp = head;

    //traverses and searches for deleteData
    while(curr->next != nullptr && curr->data != deleteData){

        temp = curr;
        curr = curr->next;
    }

    //checks for the value of curr before deletion
    if(curr == nullptr){

        cout << deleteData << " is not in the list";

    }else if(curr == head){
        
        //if deleteData is in head we need to re-assign head 
        head = head->next;
    }else{

        /*temporarily stores data to be deleted in delPtr
        then re-assigns pointers to patch things up*/
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
    }

    delete delPtr;
}


void List::PrintNode(){

    if(head != nullptr){

        curr = head;

        cout << "Data\t" << "CURR\t" << "Curr->next\t";
        cout << endl << "_________________________________\n";

        while(curr != nullptr){

            cout << curr->data << "\t" << curr << "\t" << curr->next << endl;
            curr = curr->next; //traverses pointer to the next one
        }

        cout << "\nEnd of Linked List";

    }else{

        cout << "List is empty";
    }
}

void List::InsertNode(int insertData, int place){

    if(head != nullptr){

        curr = head;

        //Create a new node thru memory allocation
        node* n1 = new node;
        n1->data = insertData;
        n1->next = nullptr;


        for(int i=0; i<place-1; i++){

            curr = curr->next;
        }
        
        n1->next = curr->next;
        curr->next = n1;

    }else{

        AddNode(insertData);
    }

}