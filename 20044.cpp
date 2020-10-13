#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int N;
vector<int>V;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0, temp = 0; i < N * 2; i++) {
		cin >> temp;
		V.push_back(temp);
	}
	sort(V.begin(), V.end());
	int MIN = INT_MAX;
	for (int i = 0; i < N; i++) {
		int temp = V[i] + V[N * 2 - 1 - i];
		if (temp < MIN)MIN = temp;
	}
	cout << MIN;
	return 0;
}