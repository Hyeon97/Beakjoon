#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

ll N, M;
vector<ll>V;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}

	sort(V.begin(), V.end());
	ll l = 1, r = V.back();
	ll out = 0;//최대 길이
	while (l <= r) {
		ll count = 0;
		ll m = (l + r) / 2;
		for (int i = 0; i < N; i++) {
			count += (V[i] / m);
		}
		if (count >= M) {
			if (out < m)out = m;
			l = m + 1;
		}
		else r = m - 1;

	}
	cout << out;
	return 0;
}