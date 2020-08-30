#include <iostream>
#include <algorithm>

using namespace std;

int N, M,cnt;
int A[50][50], B[50][50];

void Reverse(int x, int y) {
	cnt++;
	for (int i = 0; i <  3; i++) {
		for (int j = 0; j <  3; j++) {
			if (A[x+i][y+j])A[x+i][y+j] = 0;
			else A[x+i][y+j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); //cin.tie(NULL); 
	cout.tie(NULL);
	scanf_s("%d %d",&N, &M);
	//cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> A[i][j];
			scanf_s("%1d", &A[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> B[i][j];
			scanf_s("%1d", &B[i][j]);
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				Reverse(i,j);
			}
		}
	}
	bool same = true;
	for (int i = 0; i < N; i++) {
		if (same) {
			for (int j = 0; j < M ; j++) {
				if (A[i][j] != B[i][j]) {
					cout << -1;
					same = false;
					break;
				}
			}
		}
	}
	if(same)cout << cnt;


	return 0;
}
