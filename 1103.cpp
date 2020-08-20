#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[51][51], dp[301][301];
bool v[51][51];
int n, m;
//������ �Ʒ� ���� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int DFS(int Y, int X) {
	//���� �ʰ� �Ǵ� �����ΰ�쿣 0����
	if (X < 0 || X >= m || Y < 0 || Y >= n || map[Y][X] == 0)return 0;
	//��ȸ���� ��ȸ��ο��� �̹� �湮�� �� �� ������ ����Ŭ�� ���� �Ѵٰ� �Ǵ� >> ���ѹݺ� ���� >> -1 ����� ��������
	if (v[Y][X]) {
		cout << -1;
		exit(0);
	}
	//�� ��ǥ�� dp���� 0�� �ƴѰ�� �� ����
	if (dp[Y][X] != -1)return dp[Y][X];
	//�湮 üũ
	v[Y][X] = true;
	dp[Y][X] = 0;
	for (int i = 0; i < 4; i++) {
		int x = X + map[Y][X] * dx[i];
		int y = Y + map[Y][X] * dy[i];
		dp[Y][X] = (dp[Y][X] > DFS(y, x) + 1) ? dp[Y][X] : DFS(y, x) + 1;
	}
	v[Y][X] = false;
	return dp[Y][X];
}

int main() {
	cin >> n >> m;
	char temp;
	memset(dp, -1, sizeof(dp));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> temp;
			if (temp != 'H')map[y][x] = temp - '0';
			else map[y][x] = 0;
		}
	}
	cout << DFS(0, 0);


	return 0;
}