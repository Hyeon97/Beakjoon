#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//큐 사용버전 (조금 더 느림)
//int solution(int n) {
//	int answer = 0;
//	int sum = 0;
//	queue<int>q;
//	for (int i = 1; i <= n+1; i++) {
//		if (sum < n) {
//			q.push(i);
//			sum += i;
//		}
//		else {
//			if (sum == n)answer++;
//			while (sum >= n) {
//				sum -= q.front();
//				q.pop();
//				if (sum == n)answer++;
//			}
//			i--;
//		}
//	}
//	return answer;
//}

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= n + 1; i++) {
		int sum = i;
		for (int j = i + 1; j <= n; j++) {
			sum += j;
			if (sum == n) answer++;
			if (sum >= n)break;
		}
	}
	return answer+1;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(15);
	return 0;
}