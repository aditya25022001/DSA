// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) 
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isValid(int& r, int& c, int& m){
    return (r>=0 && r<m && c>=0 && c<m);
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m=grid.size();
    if(m==0) return -1;        
    if(grid[0][0] || grid[m-1][m-1]) return -1;
    int nr, nc;
    queue<pair<int,int>> q;
    vector<vector<int>> d = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};
    q.push({ 0,0 });
    grid[0][0]=1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur.first==m-1 && cur.second==m-1) return grid[cur.first][cur.second];
        for(auto i:d){
            nr=cur.first+i[0], nc=cur.second+i[1];
            if(isValid(nr,nc,m) && grid[nr][nc]==0){
                q.push({ nr,nc });
                grid[nr][nc]=1+grid[cur.first][cur.second];
            }
        }
    }
    return -1;
}
