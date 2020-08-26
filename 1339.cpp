#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Alpha[26];

bool cmp(const int& a, const int& b) {
	if (a > b)return true;
	else return false;
}


int main() {
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = temp.length()-1, pow = 1; j>=0; j--, pow *= 10) {
			Alpha[temp[j] - 'A'] += pow;
		}
	}
	sort(Alpha, Alpha + 26, cmp);
	int num = 9;
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (Alpha[i])sum += (Alpha[i] * num--);
	}
	cout << sum;
	return 0;
}