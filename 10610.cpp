//30�� ����� ���ϸ������ڸ��� ������ 0 �̾����
//�� �ڸ����� ������ 3�ǹ��������

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int arr[10];
ll sum;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	for (ll i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
		sum += (s[i] - '0');
	}
	if (!arr[0] || sum % 3)cout << -1;
	else {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
