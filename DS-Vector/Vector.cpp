#include <iostream>
#include <time.h>
#include "Vector.h"
#include <algorithm>
#include <vector>
using namespace std;

//constructor
Vector::Vector(int number){

    srand(time(nullptr));

    for(int i=0; i<number; i++){

        newVector.push_back(rand() % 100);
    }
}

void Vector::PrintVector(){

    for(auto a: newVector){

        cout << a << " ";
    }

    cout << endl;
}

void Vector::SortVector(){

    int number;

    cout << "\n1 - Increasing\n" << "2 - Decreasing\n";

    cin >> number;

    switch(number){

        case 1:
            sort(newVector.begin(),newVector.end());
            break;

        case 2:
            sort(newVector.begin(),newVector.end(),greater<int>());
            break;
        
        default:
            sort(newVector.begin(),newVector.end());

    }
}

void Vector::InsertVector(int place, int number){

    newVector.insert(newVector.begin() + place, number);
}

void Vector::DeleteVector(int place){

    vector<int>::iterator it = newVector.begin();
    newVector.erase(it + place);
}