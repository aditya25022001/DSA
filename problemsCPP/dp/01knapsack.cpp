#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int max(int a,int b){
    return a>b ? a : b;
}

int dp[12][12];
void set(){
    memset(dp,-1,sizeof(dp));
}

int knapsack(int wt[],int val[], int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n-1]<=W){
        return dp[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else{
        if(wt[n-1]>W){
            return dp[n][W] = knapsack(wt,val,W,n-1);
        }
    }
}

int zeroOne(vector<string>& strs, int m, int n, int index, vector<vector<int>>& zo, vector<vector<vector<int>>>& dp){
    if(index==strs.size() || m+n==0) return 0;
    if(dp[m][n][index]>0) return dp[m][n][index];
    int consider=0;
    if(zo[index][0]<=m && zo[index][1]<=n) 
        consider=1+zeroOne(strs,m-zo[index][0], n-zo[index][1], index+1, zo,dp);
    int skip=zeroOne(strs,m, n, index+1, zo,dp);
    return dp[m][n][index] = max(consider,skip);
}

int main(){
    set();
    vector<string> a = {"10","0001","111001","1","0"};
    return 0;
}