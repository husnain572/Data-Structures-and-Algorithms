#include<iostream>
#include<cstring>
using namespace std;

bool is_palindrom(char word[], int n){
    int st=0;
    int end=n-1;
    while(st<=end){
        if(word[st]!=word[end]){
            return false;
        }else{
        st++;
        end--;
        }
        }
        return true;
}
int main(){
char word[]="racecar";
is_palindrom(word, strlen(word));
cout<<is_palindrom(word, strlen(word));
return 0;
}
