#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx = 0;
	sort(people.begin(), people.end());
	while (people.size() > idx) {//앞에서부터 온 idx가 남은사람 수만큼이 되면 종료
		//2명 태울수 있으면 2명다 보냄
		if (people[idx] + people.back() <= limit) {
			answer++; idx++;
		}
		//2명 안되는경우 큰놈만 보냄
		else answer++;
		//보내버린 큰놈 제거
		people.pop_back();
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ 10,20,30,40,50,60,70,80,90 },100);
	return 0;
}