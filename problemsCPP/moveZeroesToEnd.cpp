#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> a = {1, 2, 0, 4, 3, 0, 5, 0};
    int count=0;
    for(int i=0;i<a.size();++i){
        if(a[i]==0){
            count++;
            a.erase(a.begin()+i);
        }
    }
    for(int i=0;i<count;++i){
        a.push_back(0);
    }
    for(auto i:a) cout<<i<<" ";
    return 0;
}