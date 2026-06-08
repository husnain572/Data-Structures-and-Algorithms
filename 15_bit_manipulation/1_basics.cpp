// Bit Manipulation
/*
Bitwise AND & :
0 & 1 --> 0
0 & 0 --> 0
1 & 0 --> 0
1 & 1 --> 1

Example:  What is AND operation of 3 & 5?
    00011
&   00101
--------------
    00001
    
So, 00001 = 1 of base 10.    
&& --> logical AND
& --> Bitwise AND


Bitwise OR | 
0 | 0 -> 0
0 | 1 -> 1
1 | 0 -> 1
1 | 1 -> 1

Example:  What is OR operation of 3 & 5?
    0011
|   0101
--------------
    0111
    
So, 0111 = 7 of base 10. 

|| --> logical OR
| --> Bitwise OR

Bitwise XOR
Rule: same -->0, different --> 1
0 ^ 0 --> 0
1 ^ 1 --> 0
1 ^ 0 --> 1
0 ^ 1 --> 1


    0011
^   0101
--------------
    0110
    
So, 0110 = 6 of base 10. 

*/

#include<iostream>
using namespace std;

int clearIthBit(int num, int i){
    int bitMask=~(1<<i);
    return num & bitMask;
}
int main(){

    cout<<(3 & 5) <<endl;
    cout<<(3 | 5) <<endl;
    cout<<(3 ^ 5) <<endl;
    cout<< (~6)<<endl;
    cout<< (~0)<<endl;
    cout<<(7>>2)<<endl;
    cout<<(7<<2)<<endl;
    cout<< (~4)<<endl;
    cout<< (8>>2)<<endl; 

    cout<<endl;
    cout<<clearIthBit(6,1);
    return 0;

}

// Bit masks are used to access specific bits in a byte of data.