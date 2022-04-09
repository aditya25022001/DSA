#include<iostream>
#include <cstring>

using namespace std;

int dp[1000];
void set(){
    memset(dp,-1,sizeof(dp));
}

int fibonacci(int n){
    if(n<=1){
        return dp[n] = n;
    }
    else{
        if(dp[n]!=-1){
            return dp[n];
        }
        else{
            return dp[n] = fibonacci(n-1)+fibonacci(n-2);
        }
    }
}

int main(){
    set();
    int n;
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}