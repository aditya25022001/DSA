#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int recurrence(int index, vector<int>& arr, vector<int>& dp){
    if(index==0) return arr[index];
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int pick = arr[index] + recurrence(index-2, arr, dp);
    int noPick = 0+ recurrence(index-1,arr,dp);
    return dp[index] = max(pick, noPick);
}
// calculate the maximum sum with out adjacent
int findMaxSum(vector<int>& arr, int n) {
    // code here
    vector<int> dp(n,-1);
    return recurrence(n-1,arr,dp);
}

int main(){
    vector<int> arr={5, 5, 10, 100, 10, 5};
    cout<<findMaxSum(arr,6);
    return 0;
}                                                                   