#include <iostream> 
#include <algorithm>

using namespace std;

int n, c;
int arr[200001];
int ans = 0;

bool ch(int l) {
	int cnt = 1;
	int p = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - p >= l)cnt++,p=arr[i];
		if (cnt >= c)return true;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);

	int l = 1, r = arr[n-1]-arr[0];

	while (l <= r) {
		int m = (l + r) / 2;
		if (ch(m)) {
			ans = ans > m ? ans : m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	cout << ans;
	return 0;
}