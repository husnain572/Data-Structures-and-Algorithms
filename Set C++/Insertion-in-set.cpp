#include<iostream>
#include<set>
using namespace std;
int main(){
	set<string> inviteList;
	int n;
	cin>>n;
	
	while(n--){
		string name;
		cin>>name;
		inviteList.insert(name);
	}
	cout<<"The list of guests is:"<<endl;
	for (auto itr:inviteList){
		cout<<itr<<" ,";
	}cout<<endl;
	return 0;
}
