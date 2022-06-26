// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.


// Approach --> visit all cells starting from 0 and mark all 8 neighbouring cells as 1+the value in current cell
// depicting the distance that have covered until now
// do the value updations only when the cell is valid and value is 0 
// if reach the end return result

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