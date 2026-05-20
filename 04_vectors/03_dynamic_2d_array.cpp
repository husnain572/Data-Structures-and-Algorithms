#include<iostream>
using namespace std;

int main(){
    int rows, cols;
    cout<<"Enter rows : ";
    cin>>rows;
    cout<<"Enter columns : ";
    cin>>cols;
    
    int* *matrix = new int*[rows];
    
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    
    // data store
    int x=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
        matrix[i][j]=x++;
        cout<<matrix[i][j]<<" ";
        }     
        cout<<endl;
    }
    // both are same
    cout<<matrix[2][2]<<endl;
    cout<<*(*(matrix+2)+2)<<endl;
    return 0;
}
