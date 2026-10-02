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
int depthOfBT(Node* root){
    if(root == NULL){
        return 0;
    }
    int left_depth = depthOfBT(root->left); 
    int right_depth = depthOfBT(root->right); 
    return max(left_depth, right_depth)+1;

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
    cout<<"Depth of Binary Tree is: "<<depthOfBT(root)<<endl;
    return 0;
}