#include<iostream>
using namespace std;
void even_odd(int num){
if((num & 1 )== 0) {
    cout<<"Even";
}else{
    cout<<"Odd";
    
}
}
int main(){
    even_odd(9);
    return 0;
}