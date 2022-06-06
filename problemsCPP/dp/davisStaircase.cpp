#include<iostream>
#include<vector>

using namespace std;

vector<long int> stair(37,-1);
int stepPerms(int n) {
    if(n<1){
        return n;
    }
    else{
        switch(n){
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 4;
            default:
                if(stair[n]!=-1)
                    return stair[n];
                return stair[n] = stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3);
        }
    }
}