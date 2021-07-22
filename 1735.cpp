#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int u,u1, u2, d,d1, d2;

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
	cin >> u1 >> d1 >> u2 >> d2;
	int G;
	G = gcd(u1, d1);
	u1 /= G;
	d1 /= G;
	G = gcd(u2, d2);
	u2 /= G;
	d2 /= G;
	d = d1 * d2;
	u = u1 * d2 + u2 * d1;
	G = gcd(u, d);
	cout << u / G << ' ' << d / G;

	return 0;
}
