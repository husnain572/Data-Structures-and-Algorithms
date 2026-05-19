// String in C++
// OOPS: Class, Object, Member Functions & properties
// C++ Strings are objects of pre-defined string class in STL
// C++ Strings have useful member functions
// C++ Strings are dynamic (their size can change at run time).
// C++ Strings support operators like +, ++, >, < etc.
// C++ Strings are stored contiguously in memory.
#include<iostream>
#include<cstring>
using namespace std;


int main(){
string str="Hello";
cout<<str<<endl;
str="World";
cout<<str<<endl;
// how to get string as an input
string str1;
getline(cin, str1);
cout<<str1<<endl;
cout<<str[2];

  // for each loop
    string str="Husnain Husnain Husnain";
    for(char ch:str){
    cout<<ch<<" ";
    }
    cout<<endl;
    // String Member Functions
    cout<<str.length()<<"\n";
    cout<<str.at(3)<<"\n";
    cout<<str.substr(1,4)<<"\n";
    cout<<str.find("nain")<<"\n";
    cout<<str.find("nain",7)<<"\n";
return 0;
}
