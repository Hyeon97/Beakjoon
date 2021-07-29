#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;
ll arr[500][500];
ll dp[500][500];
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	ll sum = 0;
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	ll M = 0;
	for (int i = 0; i < n; i++) {
		M = max(dp[n - 1][i], M);
	}
	cout << M;
	return 0;
}