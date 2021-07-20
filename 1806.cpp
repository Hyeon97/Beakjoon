#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];
int n,L=100001;
long long s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)cin >> arr[i];
	int st = 0, ed = 0;
	long long sum = 0;
	while (st <= ed && ed <= n) {
		if (sum == s) {
			if (ed - st < L) {
				L = ed - st;
			}
		}
		if (sum < s) sum += arr[ed++];
		else {
			sum -= arr[st++];
			if (sum == s) {
				if (ed - st < L) {
					L = ed - st;
				}
				if (st > ed) {
					int temp = st;
					st = ed;
					ed = temp;
				}
			}

		}
	}
	L == 100001 ? cout << 0 : cout << L;

	return 0;
}
