// <cstring> functions
// - strcpy(dest,src) : to string from src to dest
// - strcat(str1, str2 ) : to concatenate/join str1 with str2
// - strcmp(str1, str2) : compares 2 strings based on values (-ve,0,+ve)
#include<iostream>
#include<cstring>
using namespace std;


int main(){

char str1[100];
char str2[50]="Husnain Malik";
char str3[50]=" Awan";
strcpy(str1,str2);
strcat(str2, str3);
cout<<str1<<endl;
cout<<str2<<"\n";
cout<<strcmp(str2,str3)<<endl;
return 0;
}
