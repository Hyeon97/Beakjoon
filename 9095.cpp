#include <iostream>

using namespace std;

int arr[12];
int main() {
	int t;
	cin >> t;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	int temp;
	for (int i = 0; i < t; i++) {
		cin >> temp;
		for (int j = 4; j <= temp; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		cout << arr[temp] << '\n';
	}



	return 0;
}