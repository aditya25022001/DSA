#include<iostream>
#include <cstring>

using namespace std;

int dp[1000];
void set(){
    memset(dp,-1,sizeof(dp));
}

int tribonacci(int n){
    switch(n){
        case 0:
            return dp[n] = 0;
        case 1:
            return dp[n] = 1;
        case 2:
            return dp[n] = 1;
        default:
            if(dp[n]!=-1){
                return dp[n];
            }
            return dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
}

int main(){
    set();
    int n;
    cin>>n;
    cout<<tribonacci(n);
    return 0;
}