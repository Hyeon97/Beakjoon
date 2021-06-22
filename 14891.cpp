#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int arr[5][8];

int right(int n) {//시계방향으로 돌림
	if (n == 0)return 7;
	else return--n;
}

int left(int n) {//반시계방향으로 돌림
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
	//체크할 인덱스 1번톱니 2, 2번톱니 2,6 3번톱니 2,6 4번톱니 6
	int idx1 = 2, idx2 = 2, idx22 = 6, idx3 = 2, idx33 = 6, idx4 = 6;
	//각 톱니 12시방향 인덱스
	int idx1t = 0, idx2t = 0, idx3t = 0, idx4t = 0;
	cin >> k;
	while (k--) {
		cin >> num >> d;
		if (num == 1) {
			if (d == 1) {//시계방향
				if (arr[1][idx1] != arr[2][idx22]) {//1,2톱니 마주보는 극 다른경우
					if (arr[2][idx2] != arr[3][idx33]) {//2,3톱니 마주보는 극 다른경우
						if (arr[3][idx3] != arr[4][idx4]) {//3,4 톱니 마주보는 극 다른경우
						//4회전
							idx4t = left(idx4t);
							idx4 = left(idx4);
						}
						//3회전
						idx3t = right(idx3t);
						idx3 = right(idx3);
						idx33 = right(idx33);
					}
					//2회전(반시계)
					idx2t = left(idx2t);
					idx2 = left(idx2);
					idx22 = left(idx22);
				}

				//1회전
				idx1t = right(idx1t);
				idx1 = right(idx1);
			}

			else {//반시계 방향
				if (arr[1][idx1] != arr[2][idx22]) {//1,2톱니 마주보는 극 다른경우
					if (arr[2][idx2] != arr[3][idx33]) {//2,3톱니 마주보는 극 다른경우
						if (arr[3][idx3] != arr[4][idx4]) {//3,4 톱니 마주보는 극 다른경우
							//4회전
							idx4t = right(idx4t);
							idx4 = right(idx4);
						}
						//3회전(시계)
						idx3t = left(idx3t);
						idx3 = left(idx3);
						idx33 = left(idx33);
					}
					//2회전(반시계)
					idx2t = right(idx2t);
					idx2 = right(idx2);
					idx22 = right(idx22);
				}

				//1회전
				idx1t = left(idx1t);
				idx1 = left(idx1);
			}

		}
		if (num == 2) {
			if (d == 1) {//시계
				if (arr[2][idx2] != arr[3][idx33] && arr[3][idx3] != arr[4][idx4]) {//3,4 양쪽 모두 마주보는 극 다른경우
						//4회전(시계)
					idx4t = right(idx4t);
					idx4 = right(idx4);
				}
				if (arr[1][idx1] != arr[2][idx22]) {//1 다른경우
					//1회전(반시계)
					idx1t = left(idx1t);
					idx1 = left(idx1);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//3 다른경우
					//3회전(반시계)
					idx3t = left(idx3t);
					idx3 = left(idx3);
					idx33 = left(idx33);
				}
				//2회전
				idx2t = right(idx2t);
				idx2 = right(idx2);
				idx22 = right(idx22);

			}
			else {//반시계
				if (arr[2][idx2] != arr[3][idx33] && arr[3][idx3] != arr[4][idx4]) {//3,4 양쪽 모두 마주보는 극 다른경우
						//4회전(반시계)
					idx4t = left(idx4t);
					idx4 = left(idx4);
				}
				if (arr[1][idx1] != arr[2][idx22]) {//1 다른경우
					//1회전(시계)
					idx1t = right(idx1t);
					idx1 = right(idx1);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//3 다른경우
					//3회전(시계)
					idx3t = right(idx3t);
					idx3 = right(idx3);
					idx33 = right(idx33);
				}
				//2회전(반시계)
				idx2t = left(idx2t);
				idx2 = left(idx2);
				idx22 = left(idx22);
			}
		}
		if (num == 3) {
			if (d == 1) {//시계
				if (arr[1][idx1] != arr[2][idx22] && arr[2][idx2] != arr[3][idx33]) {//1,2 양쪽 모두 마주보는 극 다른경우
						//1회전(시계)
					idx1t = right(idx1t);
					idx1 = right(idx1);
				}
				if (arr[4][idx4] != arr[3][idx3]) {//4 다른경우
					//4회전(반시계)
					idx4t = left(idx4t);
					idx4 = left(idx4);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//2 다른경우
					//2회전(반시계)
					idx2t = left(idx2t);
					idx2 = left(idx2);
					idx22 = left(idx22);
				}
				//3회전
				idx3t = right(idx3t);
				idx3 = right(idx3);
				idx33 = right(idx33);

			}
			else {//반시계
				if (arr[1][idx1] != arr[2][idx22] && arr[2][idx2] != arr[3][idx33]) {//1,2 양쪽 모두 마주보는 극 다른경우
						//1회전(시계)
					idx1t = left(idx1t);
					idx1 = left(idx1);
				}
				if (arr[4][idx4] != arr[3][idx3]) {//4 다른경우
					//4회전(반시계)
					idx4t = right(idx4t);
					idx4 = right(idx4);
				}
				if (arr[2][idx2] != arr[3][idx33]) {//2 다른경우
					//2회전(시계)
					idx2t = right(idx2t);
					idx2 = right(idx2);
					idx22 = right(idx22);
				}
				//3회전
				idx3t = left(idx3t);
				idx3 = left(idx3);
				idx33 = left(idx33);
			}
		}
		if (num == 4) {
			if (d == 1) {//시계방향
				if (arr[4][idx4] != arr[3][idx3]) {//4,3톱니 마주보는 극 다른경우
					if (arr[3][idx33] != arr[2][idx2]) {//2,3톱니 마주보는 극 다른경우
						if (arr[2][idx22] != arr[1][idx1]) {//1,2 톱니 마주보는 극 다른경우
						//1회전
							idx1t = left(idx1t);
							idx1 = left(idx1);
						}
						//2회전
						idx2t = right(idx2t);
						idx2 = right(idx2);
						idx22 = right(idx22);
					}
					//3회전(반시계)
					idx3t = left(idx3t);
					idx3 = left(idx3);
					idx33 = left(idx33);
				}

				//4회전
				idx4t = right(idx4t);
				idx4 = right(idx4);
			}

			else {//반시계 방향
				if (arr[4][idx4] != arr[3][idx3]) {//4,3톱니 마주보는 극 다른경우
					if (arr[3][idx33] != arr[2][idx2]) {//3,2톱니 마주보는 극 다른경우
						if (arr[2][idx22] != arr[1][idx1]) {//2,1 톱니 마주보는 극 다른경우
							//1회전
							idx1t = right(idx1t);
							idx1 = right(idx1);
						}
						//2회전(반시계)
						idx2t = left(idx2t);
						idx2 = left(idx2);
						idx22 = left(idx22);
					}
					//3회전(시계)
					idx3t = right(idx3t);
					idx3 = right(idx3);
					idx33 = right(idx33);
				}

				//4회전(반시계)
				idx4t = left(idx4t);
				idx4 = left(idx4);
			}
		}
	}
	cout << arr[1][idx1t] * 1 + arr[2][idx2t] * 2 + arr[3][idx3t] * 4 + arr[4][idx4t] * 8;

	return 0;
}
