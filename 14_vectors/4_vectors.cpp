// STL - Standard Template Library of C++
// It is a library (collection) of container classes, algorithms and iterators.
// It contains the implementation of common data structures like vectors, stacks, maps etc.
// There are two ways of learning Data Structure. 1- Implementation of particular data structure 2- Usage of particular data structure.
// know the implementation for interiews and know the usage of data structure is for solving problems

//Vectors
// Like Dynamic arrays that can resize dynamically at runtime. They are stored contiguously in memory.
// vector<int> vec1;
// vector<int> vec2={1,2,3,4,5};
// vector<int> vec3(5,-1);

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec(5,-1);
    cout<<vec.size()<<"\n";
    
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" "; 
        }
        cout<<endl;
    return 0;
    }

