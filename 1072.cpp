#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long X, Y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> X >> Y;
	int Z = (Y * 100) / X;
	if (Z >= 99) {//확율이 바뀔수 없는 경우
		cout << -1;
		return 0;
	}
	int l = 0, r = 1000000000;
	int ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		int tz = (100 * (Y + m)) / (X + m);
		if (Z >= tz) {
			ans = m + 1;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	cout << ans;
	return 0;
}
