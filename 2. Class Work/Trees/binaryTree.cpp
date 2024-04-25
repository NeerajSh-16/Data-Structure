#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* insertIntoBinaryTree(Node* root, int data){
    if(root == NULL){
            root = new Node(data);
            return root;
    }if(data > root->data){
        root->right = insertIntoBinaryTree(root->right, data);
    }else{
        root->left = insertIntoBinaryTree(root->left, data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBinaryTree(root, data);
        cin>>data;
    }
}
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(! q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter elements of Tree : "<<endl;
    takeInput(root);
    cout<<"Printing Tree : "<<endl;
    levelOrderTraversal(root);
    return 0;
}