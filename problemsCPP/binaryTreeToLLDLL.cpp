#include<iostream>
#include<stack>
#include<queue>

using namespace std;


struct TreeNode{
    int data;
    TreeNode *right, *left;
};

void inOrder(TreeNode*r, queue<TreeNode *> &q){
    if(!r) return;
    inOrder(r->left, q);
    q.push(r);
    inOrder(r->right,q);
}

void linkList(TreeNode* root) {
    if(root!=NULL){
        stack<TreeNode*> st;
        TreeNode *current;
        st.push(root);
        while(!st.empty()){
            current=st.top();
            st.pop();
            if(current->right!=NULL)
                st.push(current->right);
            if(current->left!=NULL)
                st.push(current->left);
            if(!st.empty())
                current->right=st.top();
            current->left=NULL;
        }   
    }
}

TreeNode * bToDLL(TreeNode *root){
    queue<TreeNode *> q;
    inOrder(root, q);
    TreeNode *prev = NULL, *head=NULL, *current=NULL;
    while(!q.empty()){
        current = q.front();
        q.pop();
        if(prev==NULL){
            head=current;
            current->left=NULL;
        }
        else{
            prev->right=current;
            current->left=prev;
        }
        prev=current;
    }
    return head;
}