#include<iostream>
using namespace std;
bool isPowerOfTwo(int num){
if(!(num & (num-1))){
    return true;
}else{
    return false;
}
}
int main(){
    cout<<isPowerOfTwo(4);
    return 0;
}