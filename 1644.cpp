#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int n;
int arr[4000001];
vector<int>v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			v.push_back(arr[i]);
			for (int j = i + i; j <= n; j += i) arr[j] = 0;
		}
	}
	int cnt = 0, sum = 0, st = 0, ed = 0;
	while (st <= ed && ed < v.size()) {
		if (sum == n) {
			cnt++;
			sum -= v[st++];
		}
		if (sum < n) {
			sum += v[ed++];
			if (sum == n) {
				cnt++;
				sum -= v[st++];
			}
		}
		if (sum > n) {
			sum -= v[st++];
			if (sum == n) {
				cnt++;
				sum -= v[st++];
			}
		}
		if (st > ed) {
			int temp = st;
			st = ed;
			ed = temp;
		}
	}
	cout << cnt;
	return 0;
}
