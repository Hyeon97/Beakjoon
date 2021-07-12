#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	int temp = 0, idx = 0;
	queue<pair<int, int>>q;
	while (!(idx == truck_weights.size())) {
		if (temp + truck_weights[idx] <= weight) {
			temp += truck_weights[idx];
			q.push({ answer,idx++ });
		}

		while (1) {
			if (q.empty())break;
			if (answer + 1 == q.front().first + bridge_length) { temp -= truck_weights[q.front().second]; q.pop(); }
			else break;
		}

		answer++;
	}

	while (!q.empty()) {
		if (answer + 1 == q.front().first + bridge_length) q.pop();
		answer++;
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(2, 10, { 7,4,5,6 });
	return 0;
}