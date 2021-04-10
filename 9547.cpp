//����
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int T, C, V;
int vote[101][101];
int total[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> C >> V;
		for (int i = 0; i <= C; i++)total[i] = 0;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < C; j++) {
				cin >> vote[i][j];			
			}total[vote[i][0]]++;
		}
		int most1 = 0;
		int mx = 0;
		for (int i = 1; i <= C; i++) {
			if (total[i] > mx) {
				most1 = i;
				mx = total[i];
			}
		}
		//�ִٵ�ǥ�ڰ� ���ݼ� �������
		if (mx > V / 2) {
			cout << most1 << ' ' << 1 << '\n';
			continue;
		}
		//�ִٵ�ǥ�ڰ� ���ݼ� �̻� �������� or 1,2���� ��ǥ���� ����
		//2�� idx ã��
		int most2 = 0;
		mx = 0;
		for (int i = 1; i <= C; i++) {
			if (i != most1 && mx < total[i]) {
				most2 = i;
				mx = total[i];
			}
		}
		int most1c = 0, most2c = 0;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < C; j++) {//��ȣ�� 2��° �ĺ����� ������
				if (vote[i][j] == most1) {
					most1c++;
					break;
				}
				else if (vote[i][j] == most2) {
					most2c++;
					break;
				}
			}
		}
		most1c > most2c ? cout << most1 << ' ' : cout << most2 << ' ';
		cout << 2 << '\n';
	}
	return 0;
}