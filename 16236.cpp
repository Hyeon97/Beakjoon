#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define i_ii pair<int, pair<int,int>>
#define ii pair<int,int>

using namespace std;

typedef struct mi {
	int dist;
	int y;
	int x;
	int size;
};

typedef struct M {
	int dist;
	int y;
	int x;
};

int n, cnt;
int map[21][21];

//�� �� �� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int>me;
int Size = 2;
int eat = 0;
queue<M>q;
vector<mi>V;

bool cmp(mi a, mi b) {
	if (a.dist < b.dist)return true;
	else if(a.dist==b.dist){
		if (a.y < b.y)return true;
		else if (a.y == b.y) {
			if (a.x < b.x)return true;
		}
	}
	return false;
}

void BFS() {
	while (1) {
		bool vi[21][21] = { 0, };
		q.push({ 0,me.first,me.second });
		while (!q.empty()) {
			M temp = q.front();
			q.pop();
			int x = temp.x;
			int y = temp.y;
			int dist = temp.dist;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1 || map[ny][nx]>Size || vi[ny][nx])continue;//���� �� �Ǵ� ������ ū����� ĭ���� ����
				q.push({ dist + 1,ny,nx });
				vi[ny][nx] = true;
				if (map[ny][nx] >0 && map[ny][nx] < Size) {//����ĭ�� ����� ũ�Ⱑ ������ ������� ���� �� ����
					V.push_back({ dist+1,ny,nx,map[ny][nx] });//���� �Ʊ������ �Ÿ�
				}
			}
		}
		if (V.empty())break;
		//���� �켱���� y�� ������ >> x�� ������
		sort(V.begin(), V.end(), cmp);
		//���� �Ǿ� ���� ����
		cnt += V[0].dist;
		me = { V[0].y,V[0].x };//����ġ > ������ ��ġ�� �̵�
		map[V[0].y][V[0].x] = 0;//�ش�ĭ �����
		//���� ������ ����
		eat++;
		if (eat == Size) {//����ũ�⸸ŭ ���� �������
			Size++;//���� ����
			eat = 0;//���� ���� �ʱ�ȭ
		}
		V.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)me = { i,j }, map[i][j] = 0;

		}
	}
	BFS();
	cout << cnt;

	return 0;
}
