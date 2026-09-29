#include <iostream>
#include <vector>
#include <queue>
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

// Build Tree
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

// Preorder
// Root -> Left -> Right
void preOrder(Node* root) {

if (root == NULL) {
    return;
}

cout << root->data << " ";

preOrder(root->left);
preOrder(root->right);
}

// Inorder
// Left -> Root -> Right
void inOrder(Node* root) {

if (root == NULL) {
    return;
}

inOrder(root->left);

cout << root->data << " ";

inOrder(root->right);
}

// Postorder
// Left -> Right -> Root
void postOrder(Node* root) {
if (root == NULL) {
    return;
}

postOrder(root->left);
postOrder(root->right);

cout << root->data << " ";

}

// Level Order
// BFS - line by line
void levelOrder(Node* root) {

if (root == NULL) {
    return;
}

queue<Node*> q;

q.push(root);

while (!q.empty()) {

    Node* curr = q.front();
    q.pop();

    cout << curr->data << " ";

    if (curr->left != NULL) {
        q.push(curr->left);
    }

    if (curr->right != NULL) {
        q.push(curr->right);
    }
}

cout << endl;
}

// Level Order - Level by Level
void levelWiseOrder(Node* root) {
if (root == NULL) {
    return;
}

queue<Node*> q;

q.push(root);
q.push(NULL);

while (!q.empty()) {

    Node* curr = q.front();
    q.pop();

    if (curr == NULL) {

        if (!q.empty()) {
            cout << endl;
            q.push(NULL);
        } else {
            break;
        }

        continue;
    }

    cout << curr->data << " ";

    if (curr->left != NULL) {
        q.push(curr->left);
    }

    if (curr->right != NULL) {
        q.push(curr->right);
    }
}

cout << endl;
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

cout << "Preorder: ";
preOrder(root);
cout << endl;

cout << "Inorder: ";
inOrder(root);
cout << endl;

cout << "Postorder: ";
postOrder(root);
cout << endl;

cout << "Level Order: ";
levelOrder(root);

cout << "Level-wise Order:" << endl;
levelWiseOrder(root);

return 0;

}
