#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int idx, int target, int ans, vector<int>num) {
	if (idx == num.size()) {
		if (ans == target)answer++;
		return;
	}
	DFS(idx + 1, target, ans + num[idx], num);
	DFS(idx + 1, target, ans - num[idx], num);
	//return 0;
}

int solution(vector<int> numbers, int target) {

	DFS(1,target,-numbers[0],numbers);
	DFS(1,target,numbers[0],numbers);
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({1,1,1,1,1},3);
	return 0;
}