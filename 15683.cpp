#include <iostream>
#include <algorithm>
#include <vector>

#define i_ii pair < int ,pair < int, int> >
using namespace std;

int Y, X, ans = 0,t_ans=987654321;
int map[9][9];//6==��, 7==���ð��ɿ���
int tmap[9][9], t2map[9][9];
vector< i_ii >cctv;
vector<int>Angle;//�� ī�޶� ���ߴ� ���� ����
//�� �Ʒ� �� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dir = 0;

void Fill_R(int i) {
	//������
	int y = cctv[i].second.first;
	int x = cctv[i].second.second;
	int nx;
	tmap[y][x] = cctv[i].first;
	while (1) {
		nx = x + dx[0];
		if (nx >= X)break; 
		if (map[y][nx] == 6) {
			tmap[y][nx] = 6; break;
		}
		if (!(1 <= map[y][nx] && map[y][nx] <= 5)) {
			tmap[y][nx] = 7;
		}
		x = nx;
	}
}

void Fill_D(int i) {
	//�Ʒ�
	int y = cctv[i].second.first;
	int x = cctv[i].second.second;
	tmap[y][x] = cctv[i].first;
	int ny;
	while (1) {
		ny = y + dy[1];
		if (ny >= Y)break;
		if (map[ny][x] == 6) {
			tmap[ny][x] = 6; break;
		}
		if (!(1 <= map[ny][x] && map[ny][x] <= 5)) {
			tmap[ny][x] = 7;
		}
		y = ny;
	}
}

void Fill_L(int i) {
	//����
	int y = cctv[i].second.first;
	int x = cctv[i].second.second;
	tmap[y][x] = cctv[i].first;
	int nx;
	while (1) {
		nx = x + dx[2];
		if (nx < 0)break; 
		if (map[y][nx] == 6) {
			tmap[y][nx] = 6; break;
		}
		if (!(1 <= map[y][nx] && map[y][nx] <= 5)) {
			tmap[y][nx] = 7;
		}
		x = nx;
	}
}

void Fill_U(int i) {
	//��
	int y = cctv[i].second.first;
	int x = cctv[i].second.second;
	tmap[y][x] = cctv[i].first;
	int ny;
	while (1) {
		ny = y + dy[3];
		if (ny < 0)break;
		if (map[ny][x] == 6) {
			tmap[ny][x] = 6; break;
		}
		if (!(1 <= map[ny][x] && map[ny][x] <= 5)) {
			tmap[ny][x] = 7;
		}
		y = ny;
	}
}

void Copy() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			tmap[i][j] = map[i][j];
		}
	}
}

void DFS(int c) {
	if (c == cctv.size()) {//���ī�޶��� ���ù��� �����Ѱ��
		Copy();
		for (int i = 0; i < c; i++) {//�� ī�޶��� ���� ���⿡ ���缭 ���� ä��
			if (cctv[i].first == 1) {//�ѹ���
				if (Angle[i] == 0) Fill_R(i);
				else if (Angle[i] == 1) Fill_D(i);
				else if (Angle[i] == 2) Fill_L(i);
				else if (Angle[i] == 3) Fill_U(i);
			}
			else if (cctv[i].first == 2) {//2����(180)��
				if (Angle[i] == 0 || Angle[i] == 2)Fill_R(i), Fill_L(i);
				else if (Angle[i] == 1 || Angle[i] == 3)Fill_D(i), Fill_U(i);
			}
			else if (cctv[i].first == 3) {//2����(90��)
				if (Angle[i] == 0) Fill_R(i), Fill_D(i);
				else if (Angle[i] == 1) Fill_D(i), Fill_L(i);
				else if (Angle[i] == 2) Fill_L(i), Fill_U(i);
				else if (Angle[i] == 3) Fill_U(i), Fill_R(i);
			}
			else if (cctv[i].first == 4) {//3����
				if (Angle[i] == 0) Fill_R(i), Fill_D(i), Fill_L(i);
				else if (Angle[i] == 1) Fill_D(i), Fill_L(i), Fill_U(i);
				else if (Angle[i] == 2) Fill_L(i), Fill_U(i), Fill_R(i);
				else if (Angle[i] == 3) Fill_U(i), Fill_R(i), Fill_D(i);
			}
			else if (cctv[i].first == 5) {//4���� ����
				Fill_R(i); Fill_D(i); Fill_L(i); Fill_U(i);
			}
		}
		//���� tmap�� ��ĭ Ȯ��
		int cnt = 0;
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (tmap[i][j] == 0)cnt++;
			}
		}
		if (cnt < t_ans) {
			t_ans = cnt;
			//���� map�ʻ��� ����
			for (int i = 0; i < Y; i++) {
				for (int j = 0; j < X; j++) {
					t2map[i][j] = tmap[i][j];
				}
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		Angle.push_back(i);
		DFS(c + 1);
		Angle.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5)cctv.push_back({ map[i][j],{ i,j } });
		}
	}

	DFS(0);
	//���� ���� Ž��
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (t2map[i][j] == 0)ans++;
		}
	}
	cout << ans;

	return 0;
}
