#include <iostream>
#include <algorithm>


using namespace std;
long long s, sum = 0;
int n = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	//1���� ���������� ���س����� �ִ밪�� ã�� �� ����
	for (int i = 1; sum <= s; i++) {
		if (sum + i <= s) {
			sum += i;
			n++;
		}
		else if (sum + i > s) {//�Ѵ¼��� �� ���� n�� �ִ밪
			cout << n;
			return 0;
		}
	}

	return 0;
}
