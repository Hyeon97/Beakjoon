#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
using namespace std;


int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	priority_queue<int, vector<int>,  greater<int>>pq;
	for (int i = 0,temp; i < N; i++) {
		cin >> temp;
		if (temp)pq.push(temp);
		else {
			if (pq.empty())cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}
