#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	if (arr[0] != 1)cout << 1;//1g¥�� �߰� ������ 1g�� ����� ����
	else {
		long long int sum = 0;//������
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if ( ( i+1<n && arr[i + 1] > sum+1 )) {//������ ���� ���԰� ���� ���� ����+1g ���� ū ��� ��������+1g�� ǥ���� �� ����
				cout << sum + 1;
				return 0;
			}
		}
		cout << sum + 1;
	}

	return 0;
}
