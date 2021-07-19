#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool re;
int N, all;
int reco[101],W[101],cnt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> all;
	for (int i = 1, temp; i <= all; i++) {
		cin >> temp;
		//�̹� ��õ�������
		if (reco[temp] > 0)reco[temp]++;
		else {
			if (cnt >= N) {//���� �������
				int ch;
				int R = 11111;
				for (int i = 1; i <= 100; i++) {
					if (!reco[i])continue;
					if (reco[i] < R) {
						R = reco[i];
						ch = i;
					}
					else if (reco[i] == R) {//��ǥ�� �������
						if (W[i] < W[ch]) {
							ch = i;
						}
					}
				}
				reco[ch] = 0;
				W[ch] = 0;
				reco[temp]++;
				W[temp] = i;
			}
			else {
				W[temp] = i;
				reco[temp]++;
				cnt++;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (W[i])cout << i << ' ';
	}

	return 0;
}
