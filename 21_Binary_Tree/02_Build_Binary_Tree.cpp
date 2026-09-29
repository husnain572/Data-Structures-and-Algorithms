#include <iostream>
#include <vector>
using namespace std;

// Node
class Node {
public:
int data;
Node* left;
Node* right;

Node(int val) {
    data = val;
    left = right = NULL;
}

};

// Build Binary Tree
// Preorder:
// Root -> Left -> Right
// -1 represents NULL

int idx = -1;
Node* buildTree(const vector<int>& preorder) {
idx++;

if (preorder[idx] == -1) {
    return NULL;
}

Node* root = new Node(preorder[idx]);

root->left = buildTree(preorder);

root->right = buildTree(preorder);

return root;


}

int main() {
vector<int> preorder = {
    1,
    2, -1, -1,
    3,
    4, -1, -1,
    5, -1, -1
};

Node* root = buildTree(preorder);

cout << "Binary tree built successfully." << endl;

return 0;
}
