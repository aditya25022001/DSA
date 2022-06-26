#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int f(int i, int j, string &a, string &b, vector<vector<int>>& d){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(d[i][j]!=-1) return d[i][j];
    if(a[i]==b[j]) return d[i][j] = f(i-1,j-1,a,b,d);
    int insert = 1+f(i,j-1,a,b,d);
    int deleteC = 1+f(i-1,j,a,b,d);
    int replace = 1+f(i-1,j-1,a,b,d);
    return d[i][j] = min(insert,min(deleteC,replace));
}
int minDistance(string word1, string word2) {
    int m=word1.size(), n=word2.size();
    vector<vector<int>> d(m,vector<int>(n,-1));
    return f(m-1,n-1,word1,word2,d);
}