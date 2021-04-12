//ÀÌºÐÅ½»ö
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

int a[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, Max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (Max < a[i])Max = a[i];
	}
	int l = 0, r = Max;
	ll out = 0;
	while (l <= r) {
		ll sum = 0;
		int temp = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			if (a[i] > temp)sum += (a[i] - temp);
		}
		if (sum >= m) {
			if (out < temp)out = temp;
			l = temp + 1;
		}
		else r = temp - 1;
	}
	cout << out;
	return 0;
}
