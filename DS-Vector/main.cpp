#include <iostream>
#include "Vector.h"
#include <vector>
#include <time.h>
using namespace std;


int main(){

    Vector v1(25);

    v1.PrintVector();

    v1.SortVector();

    v1.PrintVector();

    v1.InsertVector(2,676767);

    v1.PrintVector();

    v1.DeleteVector(2);

    v1.PrintVector();
}

