#include <iostream>
#include <cstring>
using namespace std;

int n;
long long int dp[31];

long long T(int w) {
	if (w <= 1) return 1;
	long long& temp = dp[w];
	if (temp != -1)return temp;
	temp = 2 * T(w - 2) + T(w - 1);
	return temp;
}



int main() {

	cin >> n;
	memset(dp, -1, sizeof(dp));
	int result = 0;
	if (n % 2) {//홀수인경우
		result = (T(n) + T(n / 2)) / 2;
	}
	else {
		result = (T(n) + T(n / 2) + 2 * T(n / 2 - 1)) / 2;
	}
	cout << result;
	return 0;
}