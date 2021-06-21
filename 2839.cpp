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
		//������� - 3������ ���� �����ϴ� ��� �� �� + 1
		if (dp[i - 3])dp[i] = dp[i - 3] + 1;
		//������� -5������ ���� �����ϴ� ��� �׷��� ���� ���� ���� 0�� �ƴѰ�� �̹� ���ŵ� �������� -5�� �� + 1�� ���ݰ��� ���� ���� ä��
		if (dp[i - 5])dp[i] = dp[i] ? min(dp[i],dp[i-5]+1) : dp[i-5]+1;
	}
	cout << (dp[n] == 0 ? -1 : dp[n]);
	return 0;
}

//�׸���
//int cnt = 0;
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	while (n >= 0) {
//		if (n % 5 == 0) {//����ū���� �����°� ���� ��������
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