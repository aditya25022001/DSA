#include<iostream>
#include<vector>

using namespace std;

int m, n;

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& vis, int i, int j){
    vis[i][j] = true;
    int X[] = {1, 0, -1, 0};
    int Y[] = {0, 1, 0, -1};
    for(int k = 0; k < 4; k++){
        int x = i + X[k];
        int y = j + Y[k];
        if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && matrix[x][y] >= matrix[i][j] ){
            vis[x][y] = true;
            dfs(matrix, vis, x, y);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>>ans;
    m = matrix.size();
    if(m == 0)return ans;
    n = matrix[0].size();
    vector<vector<bool>>p(m, vector<bool>(n, false)), a(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        if(!p[i][0]) dfs(matrix, p, i, 0);
        if(!a[i][n - 1]) dfs(matrix, a, i, n - 1);
    }
    for(int i = 0; i < n; i++){
        if(!p[0][i]) dfs(matrix, p, 0, i);
        if(!a[m - 1][i]) dfs(matrix, a, m - 1, i);
    }
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(p[i][j] && a[i][j]) ans.push_back({i, j});
    return ans;
}