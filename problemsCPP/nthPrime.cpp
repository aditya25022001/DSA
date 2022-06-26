#include<iostream>
#include<vector>

using namespace std;

int nthPrime(int &n){
    if(n==1) return 2;
    if(n==2) return 3;
    vector<int> prime(n+1,0);
    prime[1]=2, prime[2]=3;
    int index=1;
    for(int i=3;i<=n;i+=2){
        prime[i]=6*index-1;
        prime[i+1]=6*index+1;
        ++index;
    }
    for(auto i:prime) cout<<i<<" ";
    cout<<endl;
    return prime[n];
}
int main() {
    int n;
    cin>>n;
    cout<<nthPrime(n);
}