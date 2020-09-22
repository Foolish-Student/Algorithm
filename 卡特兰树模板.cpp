#include<iostream>

using namespace std;
int num[100000];

int Catalan(int n) {
	if (n < 2) {
		return 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			num[i] += num[j] * num[i - j - 1];
		}
	}
	return num[n];
}

int main() {
	num[0] = 1;
	num[1] = 1;
	int n;
	cin >> n;
	cout << Catalan(n);
	return 0;
}