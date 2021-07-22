#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long
using namespace std;

int N;
int num[1000001];
int LR[1000001];
int RL[1000001];

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	LR[0] = num[0];
	for (int i = 1; i < N; i++) {
		LR[i] = gcd(LR[i - 1], num[i]);
	}
	RL[N - 1] = num[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		RL[i] = gcd(RL[i + 1], num[i]);
	}
	int G, ans = -1, idx;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			G = RL[1];
		}
		else if (i == N - 1) {
			G = LR[i - 1];
		}
		else {
			G = gcd(LR[i-1], RL[i+1]);
		}

		if (num[i]%G != 0 && ans<G) {
			ans = G;
			idx = i;
		}
	}
	ans==-1 ? cout<<-1 :cout << ans << ' ' << num[idx];
	return 0;
}
