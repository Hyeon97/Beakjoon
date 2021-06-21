#include <iostream>
#include <algorithm>


using namespace std;
long long s, sum = 0;
int n = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	//1부터 순차적으로 더해나가야 최대값을 찾을 수 있음
	for (int i = 1; sum <= s; i++) {
		if (sum + i <= s) {
			sum += i;
			n++;
		}
		else if (sum + i > s) {//넘는순간 의 값이 n의 최대값
			cout << n;
			return 0;
		}
	}

	return 0;
}
