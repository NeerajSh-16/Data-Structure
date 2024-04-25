#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *left, *right;
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
node *root = NULL;
node* buildTree(node* root){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data to insert left of "<<data<<" : ";
    root->left = buildTree(root->left);
    cout<<"Enter data to insert right of "<<data<<" : ";
    root->right = buildTree(root->right);
    return root;
}
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int countLeafNodes(node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
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