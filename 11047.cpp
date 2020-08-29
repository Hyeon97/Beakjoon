#include <iostream>

using namespace std;

int N, K;
int arr[10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> arr[i];
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] > K)continue;
		cnt += K / arr[i];
		K %= arr[i];
		if (K == 0)break;
	}
	cout << cnt;

	return 0;
}