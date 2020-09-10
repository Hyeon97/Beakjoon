#include <iostream>

using namespace std;

long long dp[31][31];
int N;

long long DFS(int W, int H) {
	if (dp[W][H])return dp[W][H];

	//������ �˾��� 0���ΰ�쿣 1���� ���ڿ��� �������
	if (W == 0)return 1;
	//1��¥�� �˾��� ���丷 ���� ����
	dp[W][H] = DFS(W - 1, H + 1);
	//���� ����¥�� �˾��� �ִ°��
	if (H > 0)
		dp[W][H] += DFS(W, H - 1);

	return dp[W][H];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> N;
		if (!N)break;
		cout << DFS(N,0) << '\n';
	}

	return 0;
}