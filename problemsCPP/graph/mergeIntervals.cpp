#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<climits>

using namespace std;

void dfs(int s, vector<vector<int>>& c, vector<int>& b, int& sum, vector<bool>& v){
    v[s]=true;
    sum+=b[s-1];
    for(auto i:c[s]){
        if(!v[i]){
            dfs(i,c,b,sum,v);
        }
    }
}

void solve(vector<vector<int>>& c, vector<int>& b, int& a){
    for(auto i:c) sort(i.begin(), i.end());
    sort(c.begin(), c.end());
    vector<vector<int>> op = { c[0] };
    int s, e, le;
    for(int i=1;i<c.size();++i){
        s=c[i][0];
        e=c[i][1];
        le=op[op.size()-1][1];
        if(s<=le) op[op.size()-1][1] = max(le,e);
        else op.push_back({ s,e });
    }
    for(auto i:op){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int sum=0, maxSum=0;
    for(auto i:op){
        sum=0;
        for(auto j:i){
            sum+=b[j-1];
        }
        if(sum>maxSum) maxSum=sum; 
    }
    cout<<maxSum;
}

int main(){
    int a = 6;
    vector<int> b = { 11,2,3,15,8,22 };
    vector<vector<int>> c = { { 3,2 },{ 1,2 }, { 2,3 }, { 4,5 } };
    vector<vector<int>> d(a+1);
    for(auto i:c){
        d[i[0]].push_back(i[1]);
        d[i[1]].push_back(i[0]);
    }
    int maxSum=0, sum=0;
    vector<bool> v(a+1,false);
    for(int i=1;i<=a;++i){
        sum=0;
        if(!v[i]){
            dfs(i,d,b,sum,v);
            maxSum=max(maxSum,sum);
        }
    }
    cout<<maxSum<<" "<<endl;
}