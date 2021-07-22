#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long
using namespace std;

int N, M, K;
ll seg[1 << 21];

ll sum(int node_idx, int start, int end, int Q_left, int Q_right) {
	if (Q_left <= start && end <= Q_right)return seg[node_idx];
	if (Q_right < start || end < Q_left)return 0;
	int m = (start + end) / 2;
	return sum(node_idx * 2, start, m, Q_left, Q_right) + sum(node_idx * 2 + 1, m + 1, end, Q_left, Q_right);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	ll size = pow(2, (ll)log2(N) + 1);
	for (int i = 0; i < N; i++) {
		cin >> seg[size + i];
	}
	//세그먼트 트리 완성
	for (int i = size - 1; i >= 1; i--) {
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	for (int i = 0; i < M + K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll idx = size + b - 1;
			ll ch = c- seg[idx];
			seg[idx] = c;
			for (idx /= 2; idx >= 1; idx /= 2)seg[idx] += ch;
		}
		else if (a == 2) {
			cout << sum(1, 1, size, b, c)<<'\n';
		}
	}
	return 0;
}
