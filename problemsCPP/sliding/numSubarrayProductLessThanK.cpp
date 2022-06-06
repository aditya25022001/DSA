#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int count=0, left=0, right=0;
    long long mul=1;
    int n=nums.size();
    for(;right<n;++right){
        mul*=nums[right];
        while(left<right && mul>=k){
            mul/=nums[left++];
        }
        if(mul<k){
            count+=1+right-left;
        }
    }
    return count;
}
