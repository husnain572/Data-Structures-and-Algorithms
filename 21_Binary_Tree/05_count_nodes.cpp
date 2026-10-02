#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int idx = -1;
Node* buildTree(const vector<int>& preOrder){
idx++;
if(preOrder[idx]==-1){
    return NULL;
}
Node* root=new Node(preOrder[idx]);
root->left = buildTree(preOrder);
root->right = buildTree(preOrder);
return root;
}
int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int left_count = countNodes(root->left); 
    int right_count = countNodes(root->right); 
    return left_count + right_count + 1;

}
int main(){
    vector<int>preOrder = {
        1,
        2,-1,-1,
        3, 
        4,-1,-1,
        5,-1,-1
    };
    Node* root = buildTree(preOrder);
    cout<<"Count of all nodes in Binary Tree is: "<<countNodes(root)<<endl;
    return 0;
}