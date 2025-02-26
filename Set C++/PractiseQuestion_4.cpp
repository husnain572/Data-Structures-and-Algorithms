/*
Coding Question

Given n integers (can be duplicates), print the second smallest integer.
If it does not exist, print -l.

Input l: n= 4
1224
Output 1: 1

Input 2: n = 5
12311
Output 2: 2
*/

// Solution
#include <set>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout<<"Enter size of vector";
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int>s;
    for (auto val:v){
        s.insert(val);
    }
    auto itr=s.begin();
    itr++;
    cout<<"The second smallest element is:"<<*itr;
    return 0;
}
