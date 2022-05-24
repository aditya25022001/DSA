#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int sum=0, left=0, total=0, len=INT_MAX;
    for(int i=0;i<nums.size();++i) sum+=nums[i];
    if(sum==target) return nums.size();
    if(sum<target) return 0;
    for(int i=0;i<nums.size();++i){
        total+=nums[i];
        while(total>=target){
            len = min(len,i-left+1);
            total-=nums[left];
            left++;   
        }
    }
    return len;
}