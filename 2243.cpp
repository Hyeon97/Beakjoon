#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long
using namespace std;

int N;
ll A, B, C, S;
ll seg[1 << 21];

ll query(int node, int st, int ed, int num) {
	if (st == ed)return st;
	int m = (st + ed) / 2;
	if (seg[node * 2] >= num) return query(node * 2, st, m, num);
	else if (seg[node * 2 + 1] >= num) return query(node * 2 + 1, m + 1, ed, num-seg[node*2]);
}

void update(ll B, ll C) {
	ll idx = S + B - 1;
	seg[idx] += C;
	for(idx/=2; idx>=1; idx/=2)seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	S = pow(2, (ll)log2(1000000) + 1);
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A == 1) {
			cin >> B;
			ll temp = query(1, 1, S, B);
			cout << temp << '\n';
			update(temp,-1);
		}
		else if (A == 2) {
			cin >> B >> C;
			update(B, C);
		}
	}
	return 0;
}
