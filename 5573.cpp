#include <iostream>

using namespace std;
int H, W, N;
int map[1001][1001];
int dp[1001][1001];
pair<int, int>OUT;

void DFS(int y, int x) {
	if (x >= W || y >= H) {
		OUT = { y+1,x+1 };
		return;
	}
	if (map[y][x]) {
		if (dp[y][x]) {
			DFS(y, x + 1);
		}
		else {
			DFS(y + 1, x);
		}
	}
	else {
		if (dp[y][x]) {
			DFS(y + 1, x);
		}
		else {
			DFS(y, x + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> H >> W >> N;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0]=N;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j]) {//���������� ���°��
				//�Ʒ��� �̵�
				dp[i+1][j] = dp[i][j] / 2;
				//������ �̵�
				dp[i][j + 1] = dp[i][j] % 2 == 1 ? dp[i][j] / 2 + 1 : dp[i][j] / 2;
			}
			else {//�������� ���°��
				//�Ʒ��� �̵�
				dp[i+1][j] = dp[i][j] % 2 == 1 ? dp[i][j] / 2 + 1 : dp[i][j] / 2;
				//������ �̵�
				dp[i][j+1] = dp[i][j] / 2;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			
			dp[i][j] %= 2;
		}
	}
	
	DFS(0, 0);
	cout << OUT.first << ' ' << OUT.second;
	return 0;
}
#include <iostream>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int R, C, N;
pair<int, int> ans;
void DFS(int r, int c) {
	if (r >= R || c >= C) {
		ans = { r,c };
		return;
	}
	if (arr[r][c] == 1) {
		if (dp[r][c] == 1)
			DFS(r, c + 1);
		else
			DFS(r + 1, c);
	}
	else {
		if (dp[r][c] == 1)
			DFS(r + 1, c);
		else
			DFS(r, c + 1);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j]) {//���������� ���°��
				//�Ʒ��� �̵�
				dp[i + 1][j] = dp[i][j] / 2;
				//������ �̵�
				dp[i][j + 1] = dp[i][j] % 2 == 1 ? dp[i][j] / 2 + 1 : dp[i][j] / 2;
			}
			else {//�������� ���°��
				//�Ʒ��� �̵�
				dp[i + 1][j] = dp[i][j] % 2 == 1 ? dp[i][j] / 2 + 1 : dp[i][j] / 2;
				//������ �̵�
				dp[i][j + 1] = dp[i][j] / 2;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//��� ������ ���� ���������� ���� ������ ���������� �Ʒ��������� ����
			dp[i][j] %= 2;
		}
	}
	//N�̾������� ���� ������ Ž������
	DFS(0, 0);
	cout << ++ans.first << " " << ++ans.second << "\n";
	return 0;
}
