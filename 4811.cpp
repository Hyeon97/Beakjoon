#include <iostream>

using namespace std;

long long dp[31][31];
int N;

long long DFS(int W, int H) {
	if (dp[W][H])return dp[W][H];

	//완전한 알약이 0개인경우엔 1개의 문자열만 만들어짐
	if (W == 0)return 1;
	//1알짜리 알약을 반토막 내서 먹음
	dp[W][H] = DFS(W - 1, H + 1);
	//만약 반쪽짜리 알약이 있는경우
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