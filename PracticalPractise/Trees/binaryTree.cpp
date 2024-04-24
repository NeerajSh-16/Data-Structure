#include <iostream>
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
Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data : ";
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<" : \n";
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<" : \n";
    root->right = buildTree(root->right);

}
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int countLeafNodes(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    cout<<"\nInorder Traversal : ";
    inorder(root);
    cout<<"\nPreorder Traversal : ";
    preorder(root);
    cout<<"\nPostorder Traversal : ";
    postorder(root);
    cout<<"\nNumber of leaf Nodes : "<<countLeafNodes(root);
    return 0;
}