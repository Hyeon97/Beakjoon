#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef struct Dir {
	int x;
	int y;
};

int N, M, K;
vector<int> tage[11][11];//������ ���̸� ����
int add[11][11];//�ų� �߰� ���
int map[11][11];//���� ���� ���
Dir dir[8] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };

void spring_summer() {
	vector<int>temp;
	int dead = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tage[y][x].size() == 0)continue;
			if (tage[y][x].size()) {
				dead = 0;
				temp.clear();
				//���� ��� ���
				sort(tage[y][x].begin(), tage[y][x].end());
				for (int idx = 0; idx < tage[y][x].size(); idx++) {
					if (map[y][x] - tage[y][x][idx] < 0) {//��� �������� ���� ���
						dead += (tage[y][x][idx] / 2);
					}
					else {
						map[y][x] -= tage[y][x][idx];
						//tage[y][x][idx] += 1;
						temp.push_back(tage[y][x][idx] + 1);
					}
				}
				//���� ���� ���ȭ
				map[y][x] += dead;
				tage[y][x].clear();
				for (int idx = 0; idx < temp.size(); idx++) {
					tage[y][x].push_back(temp[idx]);
				}
				temp.clear();
			}
		}
	}
}

void fall() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tage[y][x].size() == 0)continue;
			for (int idx = 0; idx < tage[y][x].size(); idx++) {
				if (tage[y][x][idx] % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nx = x + dir[d].x;
						int ny = y + dir[d].y;
						if (nx <= 0 || ny <= 0 || nx > N || ny > N)continue;
						tage[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}
void winter() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			map[y][x] += add[y][x];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> add[y][x];
			map[y][x] = 5;
		}
	}
	for (int i = 0, y, x, age; i < M; i++) {
		cin >> y >> x >> age;
		tage[y][x].push_back(age);
	}

	while (K--) {
		//�� ������ ��м���(�ڽ��� ���̸�ŭ)�� ���� +1
		//���� ���� ���� ���� ������� ��ȯ �ش�ĭ ��� �Ѿ� += ������������/2
		spring_summer();
		//���� 8���� ���� ����
		fall();
		//�ܿ� �κ��� ���� ��� �߰�
		winter();
	}
	int ans = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tage[y][x].size())ans += tage[y][x].size();
		}
	}
	cout << ans;
	return 0;
}
