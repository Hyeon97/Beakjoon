#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[5001];
//DP
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[3] = dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		//현재숫자 - 3했을때 값이 존재하는 경우 그 값 + 1
		if (dp[i - 3])dp[i] = dp[i - 3] + 1;
		//현재숫자 -5했을때 값이 존재하는 경우 그런데 만약 지금 값이 0이 아닌경우 이미 갱신된 것임으로 -5한 값 + 1과 지금값중 작은 값을 채용
		if (dp[i - 5])dp[i] = dp[i] ? min(dp[i],dp[i-5]+1) : dp[i-5]+1;
	}
	cout << (dp[n] == 0 ? -1 : dp[n]);
	return 0;
}

//그리디
//int cnt = 0;
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	while (n >= 0) {
//		if (n % 5 == 0) {//제일큰수로 나누는게 값이 제일작음
//			cnt += n / 5;
//			cout << cnt;
//			return 0;
//		}
//		n -= 3;
//		cnt++;
//	}
//	cout << -1;
//	return 0;
//}