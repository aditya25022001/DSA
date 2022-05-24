#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool palindrome(string s){
    int length = s.length();
    for(int i=0;i<length/2;++i){
        if(s[i]==s[length-i-1]) continue;
        else return false;
    }
    return true;
}

int main(){
    cout<<palindrome("nitin")<<" "<<palindrome("aditya");
    return 0;
}