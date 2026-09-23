#include<iostream>
using namespace std;

int clearIthBit(int num, int i){
    int bitMask=~(1<<i);
    return num & bitMask;
}
int main(){
    cout<<clearIthBit(6,1);
    return 0;
}