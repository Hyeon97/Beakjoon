#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int n;
int arr[1000001];
vector<int>v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i <= 1000000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (arr[i]) {
			v.push_back(arr[i]);
			for (int j = i + i; j <= 1000000; j += i) arr[j] = 0;
		}
	}
	while (1) {
		cin >> n;
		if (n == 0)break;
		
		int idx;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= n) {
				idx = i; break;
			}
		}
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			bool f2 = false;
			for (int j = idx; j >= 0; j--) {
				if (v[i] + v[j] == n) {
					cout << n << " = " << v[i] << " + " << v[j] << '\n';
					flag = true; f2 = true;
					break;
				}
				if (v[i] + v[j] < n)break;
			}
			if (flag&&f2)break;
		}
		if (!flag)cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}
