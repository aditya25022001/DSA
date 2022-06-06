#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int f(int i, int j, int& m, int& n, string& a, string& b, vector<vector<int>>& d){
    if(i>=m || j>=n) return 0;
    if(d[i][j]!=-1) return d[i][j];
    if(a.at(i)==b.at(j)) return d[i][j]=1+f(i+1,j+1,m,n,a,b,d);
    else return d[i][j] = max(f(i+1,j,m,n,a,b,d),f(i,j+1,m,n,a,b,d));
}

int longestCommonSubsequence(string text1, string text2) {
    int t1 = text1.length()+1, t2 = text2.length()+1;
    int dp[100][100];
    for(int i=0;i<t1;++i){
        dp[i][0]=0;
    }
    for(int i=0;i<t2;++i){
        dp[0][i]=0;
    }
    for(int i=1;i<t1;++i){
        for(int j=1;j<t2;++j){
            if(text1.at(i-1)==text2.at(j-1)){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[t1-1][t2-1];
}

int main(){
    string a="abcdef";
    string b="ace";
    cout<<longestCommonSubsequence(a,b);
    vector<vector<int>> d(6,vector<int>(3,-1));
    int m=a.length();
    int n=b.length();
    cout<<'\n';
    cout<<f(0,0,m,n,a,b,d);
    return 0;
}