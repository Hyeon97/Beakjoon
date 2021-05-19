#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>

using namespace std;
int x, y, w, h, ans1 = 987654321, ans2 = 987654321;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y >> w >> h;
	w - x < x ? ans1 = w - x : ans1 = x;
	h - y < y ? ans2 = h - y : ans2 = y;
	ans1 < ans2 ? cout << ans1 : cout << ans2;
	return 0;
}