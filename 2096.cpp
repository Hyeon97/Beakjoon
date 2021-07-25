#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[100001][3], Max[3], Min[3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	Min[0] = arr[0][0], Min[1] = arr[0][1], Min[2] = arr[0][2];
	Max[0] = arr[0][0], Max[1] = arr[0][1], Max[2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		//최소 구하기
		int temp1 = Min[0], temp2 = Min[1], temp3 = Min[2];
		Min[0] = arr[i][0] + min(temp1, temp2);
		Min[1] = arr[i][1] + min(temp1, min(temp2, temp3));
		Min[2] = arr[i][2] + min(temp2, temp3);
		//최대 구하기
		temp1 = Max[0], temp2 = Max[1], temp3 = Max[2];
		Max[0] = arr[i][0] + max(temp1, temp2);
		Max[1] = arr[i][1] + max(temp1, max(temp2, temp3));
		Max[2] = arr[i][2] + max(temp2, temp3);
	}
	cout << max(Max[0], max(Max[1], Max[2])) << ' ' << min(Min[0], min(Min[1], Min[2]));
	return 0;
}
