#include <iostream>
#include <stack>

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

vector<int> preOrder(Node* node) {
    vector<int> preOrder;
    if(node == NULL)
        return preOrder;
    stack<Node*> nodes;
    nodes.push(node);
    while(!nodes.empty()){
        node = nodes.top();
        nodes.pop();
        if(node->right != NULL) nodes.push(node->right);
        if(node->left != NULL)  nodes.push(node->left);
        preOrder.push_back(node->data);
    }
    return preOrder;
}

vector<int> postOrder(Node* node) {
    vector<int> postorder;
    if(node == NULL)
        return postorder;
    stack<Node*> stack_one , stack_two ;
    stack_one.push(node);
    while(!stack_one.empty()) {
        node = stack_one.top();
        stack_one.pop();
        stack_two.push(node);
        if(node->left != NULL) {
            stack_one.push(node->left);
        }
        if(node->right != NULL) {
            stack_one.push(node->right);
        }
    }
    while(!stack_two.empty()) {
        postorder.push_back(stack_two.top()->data);
        stack_two.pop();
    }
    return postorder;
}

// TIME COMPELXITY = O(N)
// SPACE COMPELIXITY = O(N)

vector<int> inOrder(Node* root) {
    stack<Node*> stack;
    Node* node = root;
    vector<int> inorder;
    while(true) {
        if(node != NULL) {
            stack.push(node);
            node = node->left;
        }else {
            if(stack.empty()) break;
            node = stack.top();
            stack.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
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
    vector<int> pre = preOrder(root);
    for (auto node : pre) {
        cout<<node;
    }

    cout<<'\n'<<"POSTORDER"<<'\n';
    vector<int> post = postOrder(root);
    for (auto node : post) {
        cout<<node;
    }

    cout<<'\n'<<"INORDER"<<'\n';
    vector<int> in = inOrder(root);
    for(auto node: in) {
        cout<<node;
    }

    return 0;
}

