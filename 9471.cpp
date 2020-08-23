#include <iostream>

using namespace std;

int p;
//피보나치 수열을 구현하면서 n-2, n-1이 수열의 시작부분인 0,1이나올때까지 돌림

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> p;
	int n, m;
	for (int i = 0; i < p; i++) {
		cin >> n >> m;
		int t1 = 0, t2 = 1;
		int cnt = 0;
		while (1) {
			if (t1 == 0 && t2 == 1 && cnt != 0)break;
			int temp = t1;
			t1 = t2;
			t2 = (temp + t1) % m;
			cnt++;
		}
		cout << n << ' ' << cnt << '\n';
	}
	return 0;
}