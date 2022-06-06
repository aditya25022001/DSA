#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subs;
vector<int> sub;

void subsequence(vector<int>& nums, int index, vector<int> sub, int length){
    if(index==length){
        subs.push_back(sub);
        return;
    }
    else{
        sub.push_back(nums[index]);
        subsequence(nums,index+1, sub, length);
        sub.pop_back();
        subsequence(nums,index+1, sub, length);
    }
}

int main(){
    vector<int> a = { 1, 2, 3 };
    subsequence(a, 0, sub, 3);
    for(auto it:subs){
        for(auto it2:it) cout<<it2<<" ";
        cout<<endl;
    }
    return 0;
}