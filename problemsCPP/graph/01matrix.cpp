// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isValid(int& r, int& c, int& m, int& n){
    return !(r<0 || r>=m || c<0 || c>=n);
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<int>> d(m,vector<int>(n,INT_MAX));
    queue<pair<int,int>> q;
    vector<vector<int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    int new_row, new_col;

    for(int i=0;i<m;++i) for(int j=0;j<n;++j) if(mat[i][j]==0){ d[i][j]=0; q.push({ i,j }); }

    while(!q.empty()){
        auto i = q.front();
        q.pop();
        for(auto j:dir){
            new_row = i.first+j[0], new_col=i.second+j[1];
            if(isValid(new_row,new_col,m,n)){
                if(d[new_row][new_col] > d[i.first][i.second]){
                    d[new_row][new_col] = d[i.first][i.second]+1;
                    q.push({ new_row, new_col });
                }   
            }
        }
    }
    return d;
}