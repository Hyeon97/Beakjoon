#include <iostream>
#include <algorithm>

using namespace std;

//int map[17][17];
//int n, result;
//bool ch;
//
////now==0 ���� //1==���� //2==�밢��
//void DFS(int y, int x, int now) {
//	if (y == n - 1 && x == n - 1) {
//		result++;
//		return;
//	}
//	//����
//	if (now == 0) {
//		//���������� �б�
//		if (x + 1 < n && y < n && map[y][x + 1] == 0)DFS(y, x + 1, 0);
//		//������ �밢������ �б�
//		if (x + 1 < n && y + 1 < n && map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0)DFS(y + 1, x + 1, 2);
//	}
//	//����
//	else if (now == 1) {
//		//�Ʒ��� �б�
//		if (x < n && y + 1 < n && map[y + 1][x] == 0)DFS(y + 1, x, 1);
//		//������ �밢������ �б�
//		if (x + 1 < n && y + 1 < n && map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0)DFS(y + 1, x + 1, 2);
//	}
//	//���ϴ� �밢��
//	else if (now == 2) {
//		//���������� �б�
//		if (x + 1 < n && y < n && map[y][x + 1] == 0)DFS(y, x + 1, 0);
//		//�Ʒ��� �б�
//		if (x < n && y + 1 < n && map[y + 1][x] == 0)DFS(y + 1, x, 1);
//		//������ �밢������ �б�
//		if (x + 1 < n && y + 1 < n && map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0)DFS(y + 1, x + 1, 2);
//	}
//}
//
//
//int main() {
//	cin >> n;
//	for (int y = 0; y < n; y++) {
//		for (int x = 0; x < n; x++) {
//			cin >> map[y][x];
//		}
//	}
//
//	DFS(0, 1, 0);
//	
//	cout << result;
//
//	return 0;
//}


int N, dp[20][20][3] = { 0, }, r[20][20];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> r[i][j];

    dp[1][2][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int right = r[i][j + 1], down = r[i + 1][j], dia = right + down + r[i + 1][j + 1];
            if (!right) dp[i][j + 1][0] += (dp[i][j][0] + dp[i][j][2]);
            if (!down) dp[i + 1][j][1] += (dp[i][j][1] + dp[i][j][2]);
            if (!dia) dp[i + 1][j + 1][2] += (dp[i][j][0] + dp[i][j][1] + dp[i][j][2]);
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    return 0;
}