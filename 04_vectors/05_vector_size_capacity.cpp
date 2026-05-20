// Vector implementation in memory
// - size & capacity of vector
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec={1,2,3,4};
    cout<<"size : " << vec.size()<<endl;
    cout<<"capacity : " << vec.capacity()<<endl;
    cout<<"\n";
    vec.push_back(5);
    cout<<"size : " << vec.size()<<endl;
    cout<<"capacity : " << vec.capacity()<<endl;
    return 0;
    }
