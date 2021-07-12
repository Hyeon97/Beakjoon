#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx = 0;
	sort(people.begin(), people.end());
	while (people.size() > idx) {//�տ������� �� idx�� ������� ����ŭ�� �Ǹ� ����
		//2�� �¿�� ������ 2��� ����
		if (people[idx] + people.back() <= limit) {
			answer++; idx++;
		}
		//2�� �ȵǴ°�� ū�� ����
		else answer++;
		//�������� ū�� ����
		people.pop_back();
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ 10,20,30,40,50,60,70,80,90 },100);
	return 0;
}