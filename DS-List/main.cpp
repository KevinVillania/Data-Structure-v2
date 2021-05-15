#include <iostream>
#include "list.h"
using namespace std;

int main(){

    List list1;

    /*
    list1.AddNode(255);
    list1.AddNode(15);
    list1.AddNode(21);
    list1.AddNode(2);

    
    cout << list1.SearchNode(255) << endl;
    cout << list1.SearchNode(15) << endl;
    cout << list1.SearchNode(21) << endl;
    cout << list1.SearchNode(2) << endl;
    
    cout << endl;
    */

    list1.InsertNode(69,1);
    list1.InsertNode(51,1);

    cout << endl;

    list1.PrintNode();

    cout << endl;

    cout << list1.SearchNode(255) << endl;
    cout << list1.SearchNode(20) << endl;


}