#include <iostream>
//#include "BST.h"
#include "BSTPractice.h"
using namespace std;

int main(){

    BST2 bst;
    //BST bst;

    bst.AddLeaf(25);
    bst.AddLeaf(26);
    bst.AddLeaf(6);
    bst.AddLeaf(16);
    bst.AddLeaf(2);
    bst.AddLeaf(66);
    bst.AddLeaf(266);

    cout << endl;
    bst.PrintInOrder();

    bst.PrintChild(25);

    cout << endl;

    cout << bst.ReturnNode(66);

    cout << endl;

    cout << bst.FindSmallest();
}   