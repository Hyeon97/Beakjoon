#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int arr[5][8];

int right(int n) {//�ð�������� ����
	if (n == 0)return 7;
	else return--n;
}

int left(int n) {//�ݽð�������� ����
	if (n == 7)return 0;
	else return ++n;
}
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int k, num, d;
	//üũ�� �ε��� 1����� 2, 2����� 2,6 3����� 2,6 4����� 6
	int idx1 = 2, idx2 = 2, idx22 = 6, idx3 = 2, idx33 = 6, idx4 = 6;
	//�� ��� 12�ù��� �ε���
	int idx1t = 0, idx2t = 0, idx3t = 0, idx4t = 0;
	cin >> k;
	while (k--) {
		cin >> num >> d;
		if (num == 1) {
			if (d == 1) {//�ð����
				if (arr[1][idx1] != arr[2][idx22]) {//1,2��� ���ֺ��� �� �ٸ����
					if (arr[2][idx2] != arr[3][idx33]) {//2,3��� ���ֺ��� �� �ٸ����
						if (arr[3][idx3] != arr[4][idx4]) {//3,4 ��� ���ֺ��� �� �ٸ����
						//4ȸ��
							idx4t = left(idx4t);
							idx4 = left(idx4);
						}
						//3ȸ��
						idx3t = right(idx3t);
						idx3 = right(idx3);
						idx33 = right(idx33);
					}
					//2ȸ��(�ݽð�)
					idx2t = left(idx2t);
					idx2 = left(idx2);
					idx22 = left(idx22);
				}

				//1ȸ��
				idx1t = right(idx1t);
				idx1 = right(idx1);
			}

			else {//�ݽð� ����
				if (arr[1][idx1] != arr[2][idx22]) {//1,2��� ���ֺ��� �� �ٸ����
					if (arr[2][idx2] != arr[3][idx33]) {//2,3��� ���ֺ��� �� �ٸ����
						if (arr[3][idx3] != arr[4][idx4]) {//3,4 ��� ���ֺ��� �� �ٸ����
							//4ȸ��
							idx4t = right(idx4t);
							idx4 = right(idx4);
						}
						//3ȸ��(�ð�)
						idx3t = left(idx3t);
						idx3 = left(idx3);
						idx33 = left(idx33);
					}
					//2ȸ��(�ݽð�)
					idx2t = right(idx2t);
					idx2 = right(idx2);
					idx22 = right(idx22);
				}

				//1ȸ��
				idx1t = left(idx1t);
				idx1 = left(idx1);
			}

		}
		if (num == 2) {
			if (d == 1) {//�ð�
				if (arr[2][idx2] != arr[3][idx33] && arr[3][idx3] != arr[4][idx4]) {//3,4 ���� ��� ���ֺ��� �� �ٸ����
						//4ȸ��(�ð�)
					idx4t = right(idx4t);
					idx4 = right(idx4);
				}
				if (arr[1][idx1] != arr[2][idx22]) {//1 �ٸ����
					//1ȸ��(�ݽð�)
					idx1t = left(idx1t);
					idx1 = left(idx1);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//3 �ٸ����
					//3ȸ��(�ݽð�)
					idx3t = left(idx3t);
					idx3 = left(idx3);
					idx33 = left(idx33);
				}
				//2ȸ��
				idx2t = right(idx2t);
				idx2 = right(idx2);
				idx22 = right(idx22);

			}
			else {//�ݽð�
				if (arr[2][idx2] != arr[3][idx33] && arr[3][idx3] != arr[4][idx4]) {//3,4 ���� ��� ���ֺ��� �� �ٸ����
						//4ȸ��(�ݽð�)
					idx4t = left(idx4t);
					idx4 = left(idx4);
				}
				if (arr[1][idx1] != arr[2][idx22]) {//1 �ٸ����
					//1ȸ��(�ð�)
					idx1t = right(idx1t);
					idx1 = right(idx1);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//3 �ٸ����
					//3ȸ��(�ð�)
					idx3t = right(idx3t);
					idx3 = right(idx3);
					idx33 = right(idx33);
				}
				//2ȸ��(�ݽð�)
				idx2t = left(idx2t);
				idx2 = left(idx2);
				idx22 = left(idx22);
			}
		}
		if (num == 3) {
			if (d == 1) {//�ð�
				if (arr[1][idx1] != arr[2][idx22] && arr[2][idx2] != arr[3][idx33]) {//1,2 ���� ��� ���ֺ��� �� �ٸ����
						//1ȸ��(�ð�)
					idx1t = right(idx1t);
					idx1 = right(idx1);
				}
				if (arr[4][idx4] != arr[3][idx3]) {//4 �ٸ����
					//4ȸ��(�ݽð�)
					idx4t = left(idx4t);
					idx4 = left(idx4);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//2 �ٸ����
					//2ȸ��(�ݽð�)
					idx2t = left(idx2t);
					idx2 = left(idx2);
					idx22 = left(idx22);
				}
				//3ȸ��
				idx3t = right(idx3t);
				idx3 = right(idx3);
				idx33 = right(idx33);

			}
			else {//�ݽð�
				if (arr[1][idx1] != arr[2][idx22] && arr[2][idx2] != arr[3][idx33]) {//1,2 ���� ��� ���ֺ��� �� �ٸ����
						//1ȸ��(�ð�)
					idx1t = left(idx1t);
					idx1 = left(idx1);
				}
				if (arr[4][idx4] != arr[3][idx3]) {//4 �ٸ����
					//4ȸ��(�ݽð�)
					idx4t = right(idx4t);
					idx4 = right(idx4);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//2 �ٸ����
					//2ȸ��(�ð�)
					idx2t = right(idx2t);
					idx2 = right(idx2);
					idx22 = right(idx22);
				}
				//3ȸ��
				idx3t = left(idx3t);
				idx3 = left(idx3);
				idx33 = left(idx33);
			}
		}
		if (num == 4) {
			if (d == 1) {//�ð����
				if (arr[4][idx4] != arr[3][idx3]) {//4,3��� ���ֺ��� �� �ٸ����
					if (arr[3][idx33] != arr[2][idx2]) {//2,3��� ���ֺ��� �� �ٸ����
						if (arr[2][idx22] != arr[1][idx1]) {//1,2 ��� ���ֺ��� �� �ٸ����
						//1ȸ��
							idx1t = left(idx1t);
							idx1 = left(idx1);
						}
						//2ȸ��
						idx2t = right(idx2t);
						idx2 = right(idx2);
						idx22 = right(idx22);
					}
					//3ȸ��(�ݽð�)
					idx3t = left(idx3t);
					idx3 = left(idx3);
					idx33 = left(idx33);
				}

				//4ȸ��
				idx4t = right(idx4t);
				idx4 = right(idx4);
			}

			else {//�ݽð� ����
				if (arr[4][idx4] != arr[3][idx3]) {//4,3��� ���ֺ��� �� �ٸ����
					if (arr[3][idx33] != arr[2][idx2]) {//3,2��� ���ֺ��� �� �ٸ����
						if (arr[2][idx22] != arr[1][idx1]) {//2,1 ��� ���ֺ��� �� �ٸ����
							//1ȸ��
							idx1t = right(idx1t);
							idx1 = right(idx1);
						}
						//2ȸ��(�ݽð�)
						idx2t = left(idx2t);
						idx2 = left(idx2);
						idx22 = left(idx22);
					}
					//3ȸ��(�ð�)
					idx3t = right(idx3t);
					idx3 = right(idx3);
					idx33 = right(idx33);
				}

				//4ȸ��(�ݽð�)
				idx4t = left(idx4t);
				idx4 = left(idx4);
			}
		}
	}
	cout << arr[1][idx1t] * 1 + arr[2][idx2t] * 2 + arr[3][idx3t] * 4 + arr[4][idx4t] * 8;

	return 0;
}
