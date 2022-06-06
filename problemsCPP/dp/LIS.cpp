#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int f(int i, int p, int& n, vector<vector<int>>& d, vector<int>& a){
    if(i>=n) return 0;
    if(d[i][p+1]!=-1) return d[i][p+1];
    int len = f(i+1,p,n,d,a);
    if(p==-1 || a[i]>a[p]) len=max(len,1+f(i+1,i,n,d,a));
    return d[i][p+1]=len;
}

int main(){
    vector<int> a ={10,9,2,5,3,7,101,18};
    int n=a.size();
    vector<vector<int>> d(n,vector<int>(n,-1));
    cout<<f(0,-1,n,d,a);
    return 0;
}

int lengthOfLIS(vector<int>& nums) {
    int length = nums.size();
    vector<int> dp(length,1);
    for(int i=0;i<length;++i){
        for(int j=0;j<=i;++j){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}