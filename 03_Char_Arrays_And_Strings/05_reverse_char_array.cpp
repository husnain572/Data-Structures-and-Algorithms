#include<iostream>
#include<cstring>
using namespace std;

void reverse(char word[], int n){
    int st=0;
    int end=n-1;
    while(st<=end){
        swap(word[st++],word[end--]);
        }
}

int main(){
char word[]="coder";
reverse(word, strlen(word));
cout<<word<<" ";
return 0;
}
