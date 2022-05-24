#include<iostream>
#include<vector>

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