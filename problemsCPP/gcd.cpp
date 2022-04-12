#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(){
    int num1 = 4, num2 = 8;
	int ans;
	for (int i = 1; i <= min(num1, num2); i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			ans = i;
		}
	}
	int a = 4, b = 8;
	cout <<"The GCD of the two numbers is "<<gcd(a, b);
	cout <<"The GCD of the two numbers is "<<ans;
}