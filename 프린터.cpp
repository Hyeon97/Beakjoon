#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0,cnt=0;
	queue<pair<int, int>>q;
	priority_queue<int>pq;
	for (int i = 0; i < priorities.size(); i++) {
		q.push({ priorities[i],i });//중요도, 번호
		pq.push(priorities[i]);
	}
	while (!q.empty()) {
		int idx = q.front().second;
		int pri = q.front().first;
		q.pop();
		if (pq.top() == pri) {
			pq.pop();
			cnt++;
			if (idx == location) {
				answer = cnt;
				break;
			}
		}
		else q.push({pri,idx});
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ 1, 1, 9, 1, 1, 1 },0);
	return 0;
}