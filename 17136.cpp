//����
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;


int s[6] = { 0,5,5,5,5,5 };//�� ũ���� ������ �� ������
int map[10][10];
int ans,cnt;
void DFS(int X, int Y) {
	if (X == 10) {//x�� ���� ������ >> �Ʒ��ٷ� �̵�
		DFS(0, Y + 1);
		return;
	}
	if (Y == 10) {//y�� ������ �ٳ����� >> Ž�� ����
		ans = min(ans,cnt);
		return;
	}
	if (map[Y][X] == 0) {// �ش������� 0�ΰ�� Ž���� �ʿ� ���� >> �̵�
		DFS(X + 1, Y);
		return;
	}

	//5���� ������ ������ ��� ����غ�
	for (int i = 5; i > 0; i--) {

		//�����ʰ� �Ǵ� �ش�ũ���� ���� �����̰� ���°�� Ž��X
		if (X + i > 10 || Y + i > 10 || s[i]==0)continue;
		bool no = false;
		for (int y = Y; y < Y + i; y++) {
			for (int x = X; x < X + i; x++) {
				if (map[y][x] == 0) {
					no = true; break;
				}
			}
			if (no)break;
		}
		if (!no) {//������ �ִ� ���
			//������
			for (int y = Y; y < Y + i; y++) {
				for (int x = X; x < X + i; x++) {
					map[y][x] = 0;
				}
			}
			s[i]--;//�ش� ũ�� ������ �� ����
			cnt++;
			DFS(X+i,Y);

			//���� ������ ġ��
			for (int y = Y; y < Y + i; y++) {
				for (int x = X; x < X + i; x++) {
					map[y][x] = 1;
				}
			}
			s[i]++;
			cnt--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	ans = INF;
	DFS(0, 0);
	ans == INF ? cout << -1 : cout << ans;
	return 0;
}
