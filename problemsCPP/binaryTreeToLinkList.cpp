#include<iostream>
#include<stack>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *right, *left;
};

void flatten(TreeNode* root) {
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