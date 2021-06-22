#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Y, X, T;
int map[51][51];
int sp[51][51];//�ӽ� ���� �л갪 ����
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool Ac;
pair<int, int> Acc;//����û���� �Ӹ� ��ǥ(����)

void spray() {
	//�� �ڸ� ���� Ȯ��(out)
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x]>0) {//�ش���ġ�� ������ �����ϴ� ��� >> Ȯ��
				int out = map[y][x] / 5;//�Ҽ����� ����
				//4���� Ȯ��
				int cnt = 0;
				for (int D = 0; D < 4; D++) {
					int nx = x + dx[D];
					int ny = y + dy[D];
					if ( nx < 0 || ny < 0 || nx > X-1 || ny > Y-1  || map[ny][nx]==-1)continue;//���� �ʰ� or ����û���� �ִ°��� ����
					sp[ny][nx] += out;//�׿� ���� Ȯ�갪 ������
					cnt++;
				}
				//Ȯ���ϰ� ������
				map[y][x] -= out * cnt;
			}
		}
	}
	//�� �ڸ� ���� Ȯ��(in)
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] == -1)continue;
			map[y][x] += sp[y][x];
			sp[y][x] = 0;
		}
	}
}

void move() {//�ش���κ��� �׵θ��� ������
	//����ûû�� ���� ���� ������
	int x=Acc.second, y=Acc.first;
	for (y-1; y > 0; y--) {
		if (map[y][x] == -1)continue;
		map[y][x] = map[y - 1][x];
	}
	for (x; x < X-1; x++) {
		map[y][x] = map[y][x + 1];
	}
	for (y; y < Acc.first; y++) {
		map[y][x] = map[y + 1][x];
	}
	for (x; x > 0; x--) {
		if (map[y][x-1] == -1)map[y][x]=0;
		else map[y][x] = map[y][x - 1];
	}
	//map[y][x] = 0;
	//����û���� �Ʒ��� ���� ������
	x = Acc.second, y = Acc.first+1;
	for (y + 1; y < Y-1; y++) {
		if (map[y][x] == -1)continue;
		map[y][x] = map[y + 1][x];
	}
	for (x; x < X-1; x++) {
		map[y][x]=map[y][x + 1];
	}
	for (y; y > Acc.first + 1; y--) {
		map[y][x] = map[y - 1][x];
	}
	for (x; x > 0; x--) {
		if (map[y][x - 1] == -1)map[y][x] = 0;
		else map[y][x] = map[y][x - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X >> T;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
			if (!Ac && map[y][x] == -1) {//�ش���ġ�� ����û���� �����ϴ� ���
				Acc = { y,x };
				Ac = true;
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		spray();//���� Ȯ��
		move();//����û���� ����
	}
	//���� �̼����� ����
	int ans = 0;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] > 0)ans += map[y][x];
		}
	}
	cout << ans;
	return 0;
}
