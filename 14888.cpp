#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

using namespace std;
int n;
int op[4], num[12];
ll Min = 987654321, Max = -987654321;

void DFS(int cnt, int pl, int mi, int mu, int dv, ll ans) {
	if (cnt == n) {//모든숫자 다 사용한 경우
		if (ans < Min)Min = ans;
		if (ans > Max)Max = ans;
		return;
	}
	if (pl) DFS(cnt + 1, pl - 1, mi, mu, dv, ans + num[cnt]);
	if (mi)DFS(cnt + 1, pl, mi - 1, mu, dv, ans - num[cnt]);
	if (mu)DFS(cnt + 1, pl, mi, mu - 1, dv, ans * num[cnt]);
	if (dv)DFS(cnt + 1, pl, mi, mu, dv - 1, ans / num[cnt]);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> num[i];
	for (int i = 0; i < 4; i++)cin >> op[i];

	DFS(1, op[0], op[1], op[2], op[3], num[0]);//사용한 숫자수, 각 연산자별 남은수, 누적계산값
	cout << Max << '\n' << Min;
	return 0;
}
