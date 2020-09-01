#include <iostream>

using namespace std;

int N, arr[1001],cnt[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		int C = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && C < cnt[j])C = cnt[j];
		}
		cnt[i] = C+1;
		max = (max > C) ? max : C;
	}
	cout << max;


	return 0;
}
