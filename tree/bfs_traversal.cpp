#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(const int val){
        data = val;
        left = right = NULL;
    }
};

vector<vector<int> > bfs(Node* root){
    vector<vector<int> > level_order_traversal_bfs;
    if(root == NULL)
        return level_order_traversal_bfs;

    // Create a queue to hold the level of the tree;
    queue<Node*> levels;
    levels.push(root);

    while(!levels.empty()) {
        int size = levels.size();
        vector<int> level;
        for (int i = 0; i < size ; i++ ){
            Node *node = levels.front();
            levels.pop();
            if(node->left != NULL) levels.push(node->left);
            if(node->right != NULL) levels.push(node->right);
            level.push_back(node->data);
        }
        level_order_traversal_bfs.push_back(level);
    }
    return level_order_traversal_bfs;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);


    cout<<'\n'<<"LEVEL ORDER TRAVERSAL BFS"<<'\n';
    vector<vector<int> >  ans = bfs(root);

    for (vector<int> node : ans) {
        for (int data : node) {
            cout<<data;
        }
    }
    return 0;
}