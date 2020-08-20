#include <iostream>

using namespace std;

int n, out = 0;

int main() {

	cin >> n;
	for (int i = 1; i <= n; i *= 10) {
		out += n - i + 1;
	}
	cout << out;
	return 0;
}