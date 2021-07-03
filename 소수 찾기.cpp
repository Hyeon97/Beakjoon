#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

bool v[10000000];
bool use[7];
int answer = 0;

void Prime() {//�Ҽ�
	memset(v, true, sizeof(v));
	for (int i = 2; i <= sqrt(9999999); i++) {
		if (!v[i])continue;
		for (int j = i * i; j < 10000000; j += i) {
			v[j] = false;
		}
	}
	v[0] = v[1] = false;
}

void DFS(int cnt, int size, string numbers, string num) {
	if (cnt == size) {
		int sum = 0;
		//���ڿ� ����ȭ
		for (int i = num.length() - 1, up = 1; i >= 0; i--, up *= 10) {
			sum += (num[i] - '0') * up;
		}
		if (v[sum])answer++, v[sum] = false;//Ȯ���� �ش����� ���� >> �ߺ�����
		return;
	}
	for (int i = 0; i < numbers.size(); i++) {
		if (use[i])continue;
		num += numbers[i];
		use[i] = true;
		DFS(cnt + 1, size, numbers, num);
		num.pop_back();
		use[i] = false;
	}
}

int solution(string numbers) {
	Prime();
	for (int I = 1; I <= numbers.length(); I++) {//�����ϴ� ���� ����
		DFS(0, I, numbers, "");
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution("17");
	return 0;
}