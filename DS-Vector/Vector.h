#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
using namespace std;

class Vector{

    private:

        vector<int> newVector;

    public:
        Vector(int number); //constructor

        void PrintVector();
        void SortVector();//sort
        void InsertVector(int place, int number);//insert
        void DeleteVector(int place);//delete


};

#endif