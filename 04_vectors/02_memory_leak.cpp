#include<iostream>
#include<vector>
using namespace std;
/* A meomry leak occurs when programmers create a memory in a heap and forget to delete it. 
It leads to reduced performance due to depletion of available memory
*/
int* func(){
    
    int *ptr=new int;
    *ptr=1200;
    cout<<"ptr points to "<<*ptr<<endl;
    return ptr;
    }
int main(){
    int *x=func();
    cout<<*x<<endl;
     
    return 0;
}
