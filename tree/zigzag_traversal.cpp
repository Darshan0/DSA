#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(const int val) {
        data = val;
        left = right = NULL;
    }

};


vector<vector<int> > zigzagTravesal(Node* root){
    bool rightToLeft;
    vector<vector<int> > ans;
    if(root == NULL)
        return ans;

    queue<Node*> levels;
    levels.push(root);

    while(!levels.empty()){
        int size = levels.size();
        vector<int> level;
        for(int i = 0 ; i < size ; i++){
            Node* node = levels.front();
            levels.pop();
            if(node->left != NULL) levels.push(node->left);
            if(node->right != NULL) levels.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
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
    vector<vector<int> >  ans = zigzagTravesal(root);

    for (vector<int> node : ans) {
        for (int data : node) {
            cout<<data;
        }
    }
    return 0;
}
