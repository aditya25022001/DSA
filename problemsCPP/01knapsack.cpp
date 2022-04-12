#include <iostream>
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

int main(){
    set();
    return 0;
}