#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (const int val) {
        data = val;
        left = right = NULL;
    }
};

int max_depth(Node* root){
    if (root == NULL) return 0;
    int lh = max_depth(root->left);
    if(lh == -1) return -1;
    int rh = max_depth(root->right);
    if(rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;
    return fmax(lh, rh) + 1;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->right->left = new Node(6);


    cout<<'\n'<<"Balance tree or not"<<'\n';
    int mh = max_depth(root);
    cout<<mh;
    if(mh == -1) {
        cout<<'\n'<<"No"<<'\n';
    } else {
        cout<<"Yes";
    }
    return 0;
}