// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int val;
    Node *right, *left, *next;
};

Node* levelOrder(Node* root){
    if(root==NULL) return NULL;
    queue<Node* > q;
    queue<Node* > bfs;
    root->next=NULL;
    q.push(root);
    q.push(NULL);
    bfs.push(root);
    bfs.push(NULL);
    Node* r;
    while(q.size()>1){
        r=q.front();
        q.pop();
        if(r==NULL) { q.push(NULL); bfs.push(NULL); }
        else{
            if(r->left!=NULL) { q.push(r->left); bfs.push(r->left); }
            if(r->right!=NULL) { q.push(r->right); bfs.push(r->right); }                
        }
    }
    Node* head=NULL;
    while(bfs.size()>1){
        r=bfs.front();
        if(head==NULL) head=r;
        bfs.pop();
        if(r!=NULL) r->next=bfs.front();
    }
    return head;
}