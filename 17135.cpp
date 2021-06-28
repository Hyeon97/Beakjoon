//����
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct Dir {
	int y;
	int x;
};

Dir dir[3] = { {0,-1},{-1,0},{0,1} };//�� �� ��
int Y, X, D;
int map[16][16];
int map2[16][16];
bool check[16][16];
bool vi[16][16];
int ans = 0;

void go(int a1, int a2, int a3) {

	int archer[3] = { a1,a2,a3 }; // ���� �ü� ��ġ (x�� ��ǥ)
	int pos = Y; // ���� �ü� ��ġ (y�� ��ǥ)
	int kill = 0;

	// �� ���� + ���� �� ��ġ �ʱ�ȭ
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++)
		{
			map2[i][j] = map[i][j];
			check[i][j] = vi[i][j] = false;
		}
	}

	while (pos > 0)//�ü� ������ ����
	{
		for (int i = 0; i < 3; i++) // �ü� 3��
		{
			// �湮�迭 �ʱ�ȭ
			for (int j = 0; j < Y; j++) {
				for (int k = 0; k < X; k++) {
					vi[j][k] = false;
				}
			}

			queue<pair<int, int>>q;
			int x = archer[i];
			int y = pos - 1;

			q.push({ x, y });

			// �� Ž��
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				vi[y][x] = true; // �湮 ǥ��

				if (map2[y][x] == 1) // �� �߽߰�
				{
					check[y][x] = true; // ���� ǥ��
					break;
				}

				for (int j = 0; j < 3; j++) // ��,��,��
				{
					int nx = x + dir[j].x;
					int ny = y + dir[j].y;
					// ������ ���� �� ������ + �ü� �����Ÿ��� + �湮���� ���� 
					if (0 <= nx && nx < X && 0 <= ny && ny < Y && ((abs(archer[i] - nx) + abs(pos - ny) <= D)) && !vi[ny][nx])
						q.push({ nx, ny });
				}
			}
		}

		// ���� ǥ�õ� ���� ����
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (check[i][j]) map2[i][j] = 0;
			}
		}
		pos--; // �ü��� ����
	}

	// ���� �� ī��Ʈ
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (check[i][j]) kill++;
		}
	}
	ans = max(ans, kill);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X >> D;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
		}
	}
	//�ü� ��ġ
	for (int i = 0; i < X; i++) {
		for (int j = i + 1; j < X; j++) {
			for (int k = j + 1; k < X; k++) {
				go(i, j, k);//�ü� 3�� ��ġ
			}
		}
	}

	cout << ans;
	return 0;
}
