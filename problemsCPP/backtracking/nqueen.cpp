#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool boundingFunction(int r, int c, vector<string>& board, int n){
    int rt = r, ct= c;
    // upper left diagonal         
    while(r>=0 && c>=0){
        if(board[r][c]=='Q') return false;
        r--;
        c--;
    }
    r=rt, c=ct;
    // lower left diagonal         
    while(r<n && c>=0){
        if(board[r][c]=='Q') return false;
        r++;
        c--;
    }
    r=rt, c=ct;
    //left row         
    while(c>=0){
        if(board[r][c]=='Q') return false;
        c--;
    }
    return true;
}
void backtrack(int c, vector<string>& board, vector<vector<string>>& ans, int n){
    if(c==n){
        ans.push_back(board);
        return;
    }
    for(int r=0;r<n;++r){
        if(boundingFunction(r,c,board,n)){
            board[r][c]='Q';
            backtrack(c+1,board,ans,n);
            board[r][c]='.';
        }
    }
}
int totalNQueens(int n) {
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'.');
    int count=0;
    for(int i=0;i<n;++i) board[i]=s;
    backtrack(0,board,ans,n);
    return ans.size();
}