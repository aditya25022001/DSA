#include<iostream>
#include<vector>

using namespace std;

// next permutation is a number such that it is just greater than the given number

void nextPermutation(vector<int>& nums) {
    int size = nums.size()-1, decIndex=-1, min = INT_MAX, minIndex, temp;
    // find first decreasing pair from right
    for(int i=size-1;i>=0;i--){
        if(nums[i]<nums[i+1]){
            decIndex=i;
            break;
        }
    }
    // If not found just reverse or return -1 accr to question
    if(decIndex==-1){
        reverse(nums.begin(),nums.end());
    }
    else{
        // find the next greater number than the current decreasing pair 
        for(int i=decIndex+1;i<=size;++i){
            if(nums[i]<=min && nums[i]>nums[decIndex]){
                min=nums[i];
                minIndex = i;
            }
        }
        // swap the numbers i.e the dec pair and the number just greater than that
        temp = nums[decIndex];
        nums[decIndex] = nums[minIndex];
        nums[minIndex] = temp;
        // reverse the part after dec pair since we require the least of greater permutation
        reverse(nums.begin()+decIndex+1,nums.end());   
    }
}