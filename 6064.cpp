#include <iostream>
#include <algorithm>

using namespace std;

//최대 공약수
int GCD(int a, int b) {
	if (a % b == 0)return b;
	return GCD(b, a % b);
}
//최소공배수
int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

int main() {
	int t;
	cin >> t;
	int m, n, x, y;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		int Y = LCM(m, n);
		while (1) {
			if (x > Y || (x - 1) % n + 1 == y)break;
			x += m;
		}
		if (x > Y)cout << -1 << '\n';
		else cout << x << '\n';
	}
	return 0;
}