#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<climits>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class Tree{
    public:
        node* create(){
            int d;
            node* temp = new node; 
            cout<<"\nEnter data : ";
            cin>>d;
            if(d==-1) return NULL;
            temp->data=d;
            cout<<"\nLeft child : ";
            cin>>d;
            temp->left=create();
            cout<<"\nRight child : ";
            cin>>d;
            temp->right=create();
            return temp;
        }
        void inorder(node* r){
            if(!r) return;
            if(r->left) inorder(r->left);
            cout<<r->data<<" ";
            if(r->right) inorder(r->right);
        }
        void preorder(node* r){
            if(!r) return;
            cout<<r->data<<" ";
            if(r->left) preorder(r->left);
            if(r->right) preorder(r->right);
        }
        void postorder(node* r){
            if(!r) return;
            if(r->left) postorder(r->left);
            if(r->right) postorder(r->right);
            cout<<r->data<<" ";
        }
};

node* root = NULL;

int main(){
    Tree t = Tree();
    root=t.create();
    t.inorder(root);
}