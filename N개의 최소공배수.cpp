#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (b) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int solution(vector<int> arr) {
	if (arr.size() == 1)return arr[0];
	else {
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size()-1; i++) {
			int G = gcd(arr[i], arr[i + 1]);
			arr[i + 1] = (arr[i] * arr[i + 1]) / G;
		}
	}
	return arr[arr.size()-1];
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ 3,4,9,16 });
	return 0;
}