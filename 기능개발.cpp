//기능개발
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> temp;
	for (int i = 0; i < progresses.size(); i++) {
		if (((100 - progresses[i]) % speeds[i]))temp.push_back(((100 - progresses[i]) / speeds[i]) + 1);
		else temp.push_back((100 - progresses[i]) / speeds[i]);
	}
	for (int i = 0; i < temp.size(); i++) {
		int cnt = 0, j;
		for (j = i; j <= temp.size(); j++) {
			if (j == temp.size()) {
				i = j;
				break;
			}
			if (temp[j] <= temp[i])cnt++;
			else {
				i = --j;
				break;
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main(void) {
	vector<int> a = { 70 };
	vector<int> b = { 20 };
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(a, b);
	return 0;
}