#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[100001];
int N, M;

bool BH(int num) {
	int l = 0, r = N - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] == num) return 1;
		if (arr[m] < num) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0,num; i < M; i++) {
		cin >> num;
		cout << BH(num) << '\n';
	}

	return 0;
}
