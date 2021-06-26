#include <iostream>
#include <algorithm>


using namespace std;

bool ok, sub;
int N, L, ans;
int map[101][101];//����
int map2[101][101];//���μ��� ����

void check(int map[][101]) {
	int same = 0;
	for (int y = 0; y < N; y++) {
		ok = true;
		same = 0;
		int prev = -1;
		//������(�� -> ��)
		for (int x = 0; x < N; x++) {
			if (x == 0)same++, prev = map[y][x];
			else {
				if (abs(map[y][x] - prev) > 1) {
					ok = false; break;
				}
				if (map[y][x] > prev) {//������
					if (same >= L) same = 1, prev = map[y][x];
					else {
						ok = false; break;
					}
				}
				else if (map[y][x] < prev) {//������
					int st = map[y][x], i, cnt;
					bool sub = true;
					for (i = x, cnt = 0; cnt < L; cnt++, i++) {
						if (i >= N || map[y][i] != st) {
							sub = false;
							ok = false;
							break;
						}
					}
					if (sub)x = i - 1, prev = map[y][i - 1], same = 0;
				}
				else {//����
					same++;
				}
				//if (!ok)break;
			}
		}
		if (ok)ans++;
		else {//�����⿡�� ���� ã����� �������� ���ʿ� ����
			ok = true;
			same = 0;
			//������
			for (int x = N - 1; x >= 0; x--) {
				if (x == N - 1)same++, prev = map[y][x];
				else {
					if (abs(map[y][x] - prev) > 1) {
						ok = false; break;
					}
					if (map[y][x] > prev) {//������
						if (same >= L) same = 1, prev = map[y][x];
						else {
							ok = false; break;
						}
					}
					else if (map[y][x] < prev) {//������
						int st = map[y][x], i, cnt;
						bool sub = true;
						for (i = x, cnt = 0; cnt < L; cnt++, i--) {
							if (i < 0 || map[y][i] != st) {
								sub = false;
								ok = false;
								break;
							}
						}
						if (sub)x = i + 1, prev = map[y][i + 1], same = 0;
					}
					else {//����
						same++;
					}
					//if (!ok)break;
				}
			}
			if (ok)ans++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	//���� ���� ���� �Է¹���
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			 map2[x][y] = map[y][x];
		}
	}
	check(map);
	check(map2);

	cout << ans;
	return 0;
}
