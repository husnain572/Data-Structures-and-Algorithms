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
int sumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int left_sum = sumOfNodes(root->left); 
    int right_sum = sumOfNodes(root->right); 
    return left_sum + right_sum + root->data;

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
    cout<<"Sum of all nodes in Binary Tree is: "<<sumOfNodes(root)<<endl;
    return 0;
}