#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> validGene;
    for(auto i:bank) validGene.insert(i);
    if(!validGene.count(end)) return -1;
    vector<char> choices = {'A','C','G','T'};
    string current, s1;
    char eachCurrent;
    queue<string> bfs;
    unordered_set<string> visited;
    bfs.push(start);
    visited.insert(start);
    int mutations=0, size=0;
    while(!bfs.empty()){
        size=bfs.size();
        while(size--){
            current=bfs.front();
            bfs.pop();
            if(current==end) return mutations;
            for(int i=0;i<current.length();++i){
                eachCurrent=current[i];
                for(auto j:choices){
                    s1=current;
                    s1[i]=j;
                    if(s1!=current && !visited.count(s1) && validGene.count(s1)){
                        bfs.push(s1);
                        visited.insert(s1);
                    }
                }
            }
        }
        mutations++;
    }
    return -1;
}

int main(){
    return 0;
}