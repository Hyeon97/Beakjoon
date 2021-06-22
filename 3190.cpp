#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int map[101][101];//1 : ��� 2 : �� ��ġ
deque<pair<int, int>>snake;//���� ���� == ���� ����, �� ���� ��ǥ == �� ������ġ
vector<pair<int, int>>v;
//�� �� �� �Ʒ�
int dir = 0;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int N, K, L, ans;
char C;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0, x, y; i < K; i++) {
		cin >> y >> x;
		map[y][x] = 1;
	}

	cin >> L;
	for (int i = 0, num; i < L; i++) {
		cin >> num >> C;
		v.push_back({ num,C });
	}

	snake.push_back({ 1,1 });
	map[1][1] = 2;
	int cnt = 0;
	while (1) {
		ans++;
		//�Ӹ��̵�
		int nx = snake.front().second + dx[dir];
		int ny = snake.front().first + dy[dir];
		//�Ӹ��� �̵���ġ�� map�� �� �Ǵ� �ڽ��� ����� �΋H���� ��� ����
		if (nx < 1 || nx > N || ny < 1 || ny > N || map[ny][nx] == 2) {
			cout << ans;
			return 0;
		}
		//�����ϼ� �ִ� ���
		else {//��� ���°��
			if (map[ny][nx] == 0) {//��� �ȸ��� ��� ���� ����
				map[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			//�Ӹ��̵�	
			map[ny][nx] = 2;
			//���ο� �Ӹ� ��ǥ �߰�
			snake.push_front({ ny,nx });
		}
		if (cnt<v.size() && ans == v[cnt].first) {
			//�̵��Ϸ�� ������ȯ
			dir = v[cnt].second == 'L' ? (dir + 1) % 4 : (dir + 3) % 4;
			cnt++;
		}
	}
	cout << ans;

	return 0;
}
