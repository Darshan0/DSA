#include <iostream>

using namespace std;

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)

struct Node {
    int data;
    Node* left;
    Node* right;

     Node(const int val){
        data = val;
        right = left = NULL;
     }
};

void preOrder(Node* node) {
    if(node == NULL)
        return;
    cout<<node->data;
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node* node) {
    if(node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data;
}

void inOrder(Node* node) {
    if(node == NULL)
        return;
    inOrder(node->left);
    cout<<node->data;
    inOrder(node->right);
}



int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);


    cout<<'\n'<<"PREORDER"<<'\n';
    preOrder(root);

    cout<<'\n'<<"POSTORDER"<<'\n';
    postOrder(root);

    cout<<'\n'<<"INORDER"<<'\n';
    inOrder(root);

    return 0;
}

