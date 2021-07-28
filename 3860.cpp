#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define INF 987654321
using namespace std;

int W, H, G, E, y, x, y2, x2, w;
vector<pair<int, int>>edge[910];
int map[31][31];
ll dist[910];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		//�ʱ�ȭ
		for (int i = 0; i < 910; i++) {
			edge[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				map[i][j] = 0;
			}
		}
		//����
		cin >> G;
		for (int i = 0; i < G; i++) {//���� ��ǥ
			cin >> x >> y;
			map[y][x] = 1;
		}
		cin >> E;
		for (int i = 0; i < E; i++) {//�ͽ� ���� ��ǥ
			cin >> x >> y >> x2 >> y2 >> w;
			map[y][x] = 2;
			edge[y * W + x + 1].push_back({ y2 * W + x2 + 1,w });
		}
		//���� ��� ä���ֱ�
		for (int x = 0; x < W; x++) {
			for (int y = 0; y < H; y++) {
				//�����ΰ�� ��������, �����ΰ�� ������ ������ ��ηθ� �̵�����, ������������ �ȿ�����
				if (map[y][x] || (y == H - 1 && x == W - 1))continue;
				//4����
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (0 <= nx && nx < W && 0 <= ny && ny < H && map[ny][nx] != 1) {
						edge[y * W + x + 1].push_back({ ny * W + nx + 1, 1 });
					}
				}
			}
		}

		dist[1] = 0;
		bool cycle = false;
		for (int i = 0; i < W * H; i++) {//��ü Ž�� �ݺ�Ƚ��
			for (int j = 1; j < W * H; j++) {//�� ����(�����)
				if (dist[j] == INF)continue;
				for (auto next : edge[j]) {//�� ����(������)
					//�ش� �������� ���� ���� ���� && �ش������� ������ ���� ���� �� �������
					if (dist[next.first] > next.second + dist[j]) {
						dist[next.first] = next.second + dist[j];
						//i�� ������ �Դµ� ���� ���ǿ� �ɸ��� ��� >> ��������Ŭ ���� >> ���ѹ� ���Ե�
						//������ n-1�� ��ȯ�ϸ鼭 ������ ����
						if (i == W * H-1)cycle = true;
					}
				}
			}
		}
		if (cycle)cout << "Never\n";
		else {
			if (dist[W*H] == INF)cout << "Impossible\n";
			else cout << dist[W*H] << '\n';
		}
	}

	return 0;
}