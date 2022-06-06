#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *right, *left;
};

int maxDepth(TreeNode* root) {
    queue<TreeNode *> q;
    TreeNode* temp;
    int depth = 0;
    if(!root){
        return 0;
    }
    q.push(root);
    // to implicate a level         
    q.push(NULL);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp==NULL){
            depth++;
        }
        if(temp!=NULL){
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        else{
            if(!q.empty())
                q.push(NULL);
        }
    }
    return depth;
}