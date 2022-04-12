#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(),stones.end());
    int one, two, result;
    while(pq.size()>1){
        one = pq.top();
        pq.pop();
        two = pq.top();
        pq.pop();
        result = one==two ? 0 : one-two;
        pq.push(result);
    }
    return pq.top();
}

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    cout<<lastStoneWeight(stones);
}