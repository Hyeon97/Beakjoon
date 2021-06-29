//´õ¸Ê°Ô
#include <iostream> 
#include <vector> 
#include <queue>

using namespace std;

priority_queue<long long, vector<long long> , greater<long long>> pq;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	if (pq.top() < K) {
		while (!pq.empty()) {
			if (pq.top() >= K)break;
			if (pq.size() == 1 && pq.top() < K) {
				answer = -1; break;
			}
			long long first = pq.top(); pq.pop();
			long long second = pq.top(); pq.pop();
			long long temp = first + second * 2;
			pq.push(temp);
			answer++;
		}
	}
	return answer;
}