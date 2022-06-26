#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n=16;
    vector<int> dp(n,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n-1];
    return 0;
}