#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s = "geeksforgeeks";
    int k=2;
    stack<pair<char,int>> a;
    for(int i=0;i<s.length();++i){
        if(a.size()>0 && a.top().first==s.at(i)){
            if(a.top().second==k-1){
                a.pop();
            }
            else{
                a.top().second+=1;
            }
        }
        else{
            a.push({s.at(i),1});
        }
    }
    string v="";
    while(!a.empty()){
        v+=a.top().first;
        a.pop();
    }
    reverse(v.begin(),v.end());
    cout<<v;
    return 0;
}