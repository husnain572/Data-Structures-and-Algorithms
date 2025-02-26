// Set basic operations
#include<iostream>
#include<set>
using namespace std;
int main(){
	set<int>set1;
	set1.insert(2);
	set1.insert(1);
	set1.insert(8);
	set1.insert(4);
	set1.insert(12);
	set1.insert(3);
	set1.insert(9);
	set1.insert(7);
	cout<<"Size of a set is:"<<set1.size()<<endl;
	set1.insert(2);
	cout<<"Size of a set is still same:"<<set1.size();
	cout<<endl;
	
	
	set<int>::iterator itr;
	cout<<"The set is:"<<endl;
	for (itr=set1.begin();itr!=set1.end();itr++){
	    cout<<*itr<<" "; // itr is pointing the position of elements in set. For values, we used steric(*). 
	}cout<<endl;
	//Now using for each loop for traversal
	
	cout<<"The set is:"<<endl;
	for (auto value:set1){
	    cout<<value<<" ";
	}cout<<endl;
	
	// ---------------------------------------------------------
	//Deletion of elements using erase function 
	set1.erase(1);
		cout<<"The set after deletion using erase function is:"<<endl;
	for (auto value:set1){
	    cout<<value<<" ";
	}cout<<endl;
	
	//Deletion of elements using erase position
// 	auto itr=set1.begin();
	advance(itr,1);
	set1.erase(itr);
	cout<<"The set after deletion using position is:"<<endl;
	for (auto value:set1){
	    cout<<value<<" ";
	}cout<<endl;
	
	//Deletion of range elements
	auto start_itr=set1.begin();
	start_itr++;
	auto end_itr=set1.begin();
	advance(end_itr,2);
	set1.erase(start_itr,end_itr);
		cout<<"The set after deleting range of element is:"<<endl;
	for (auto value:set1){
	    cout<<value<<" ";
	}cout<<endl;
	
	
	// search operation
	if(set1.find(14)!=set1.end()){
	    cout<<"value is present"<<endl;
	}else{
	    cout<<"Value is not present"<<endl;
	}
	return 0;
}
