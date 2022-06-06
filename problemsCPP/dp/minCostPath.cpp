#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int minPath(int i, int j, int& m, int& n, vector<vector<int>>& g, vector<vector<int>>& d){
    if(d[i][j]!=-1) return d[i][j];
    if(i==m-1 && j==n-1) return d[i][j] = g[i][j];
    if(i==m-1) return d[i][j] = g[i][j] + minPath(i,j+1,m,n,g,d);
    if(j==n-1) return d[i][j] = g[i][j] + minPath(i+1,j,m,n,g,d);
    return d[i][j] = g[i][j]+min(minPath(i,j+1,m,n,g,d),minPath(i+1,j,m,n,g,d)); 
}

int main(){
    vector<vector<int>> grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> d(m,vector<int>(n,-1));
    int  i = minPath(0,0,m,n,grid,d);
    cout<<" jnkdvkjdv "<<i<<" ";
    return 0;
}

// 66477