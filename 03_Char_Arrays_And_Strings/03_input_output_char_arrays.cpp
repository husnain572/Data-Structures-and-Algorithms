#include<iostream>
#include<cstring>
using namespace std;

int main(){
// Input Output character arrays
  // One way
char word[50];
cin>>word;
cout<<"Your word is: "<<word<<"\n";
cout<<"Length : "<<strlen(word);

  // Second way
char sentence[50];
cin.getline(sentence,30); //(variable name, length, delimeter)
cout<<"Your word is: "<<sentence<<"\n";
cout<<"Length : "<<strlen(sentence);

return 0;
}
