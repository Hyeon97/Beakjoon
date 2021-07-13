#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	//들어온 숫자의 1갯수
	int tn = n;
	int nnt = 0;
	while (tn) {
		if (tn % 2)nnt++;
		tn /= 2;
	}
	for (int i = n + 1; ; i++) {
		int temp = i;
		int cnt = 0;
		while (temp) {
			if (temp % 2)cnt++;
			temp /= 2;
		}
		if (cnt == nnt)return i;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution(15);
	return 0;
}