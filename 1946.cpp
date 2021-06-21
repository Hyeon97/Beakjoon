#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int T,N,ans;
pair<int, int>arr[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		ans = 1;
		for (int i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr, arr + N);
		int st = arr[0].second;
		for (int i = 1; i < N; i++) {
			if (arr[i].second > st)continue;
			else {
				ans++;
				st = arr[i].second;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
