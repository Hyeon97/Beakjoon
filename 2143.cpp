#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int T, n, m, temp;
ll cnt;
vector<long long>A;
vector<long long>B;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < n - 1; i++) {
		long long sum = A[i];
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			A.push_back(sum);
		}

	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	for (int i = 0; i < m - 1; i++) {
		long long sum = B[i];
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			B.push_back(sum);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<long long>());
	ll a = 0, b = 0;
	while (a < A.size() && b < B.size()) {
		if (A[a] + B[b] == T) {//ÇÕ ÀÏÄ¡
			ll ac = 1, bc = 1;
			int i;
			for (i = a + 1; i < A.size(); i++) {
				if (A[i] == A[a])ac++;
				else break;
			}
			a = i;
			for (i = b + 1; i < B.size(); i++) {
				if (B[i] == B[b])bc++;
				else break;
			}
			b = i;
			cnt += ac * bc;
			
		}
		else if (A[a] + B[b] > T)b++;
		else a++;
	}
	cout << cnt;
	return 0;
}
