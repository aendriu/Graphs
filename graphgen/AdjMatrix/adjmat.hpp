#ifndef ADJMATRIX
#define ADJMATRIX
#include "../graph/graph.hpp"
#include <iostream>
#include <random>
#include <vector>

using namespace std;
namespace graphs {

template<typename Data>
class AdjMatrix : public Graph<Data> {
    
    public:

        using Graph<Data>::vcard; 

        // Constructor and Destructor
        AdjMatrix();
        AdjMatrix(ulong size);
        ~AdjMatrix() = default;
       
        // Copy and Move Costructors
        AdjMatrix(const AdjMatrix& other); // Copy constructor
        AdjMatrix(AdjMatrix&& other) noexcept; // Move constructor


        AdjMatrix& operator=(const AdjMatrix& other); // Copy assignment
        AdjMatrix& operator=(AdjMatrix&& other) noexcept; // Move assignment
        Data& operator[](const ulong) override;
        const Data& operator[](const ulong pos) const override;

        // Graph interface methods
        void addLink(ulong, ulong) override;
        void removeLink(ulong, ulong) override;
        bool hasLink(ulong, ulong) const override;
        
        void setElements(vector<Data>&);

        // utils
        void PrintAdjMatInfo()const noexcept;
        void Randomize(ulong);
        ulong Size() const noexcept override;


    private:
        vector<Data> elements;
        vector<vector<Data>> matrix;
        
};

}

#include "adjmat.cpp"

#endif