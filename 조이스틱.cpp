#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	int idx = 0;
	while (1) {
		answer += min(name[idx]-'A', 'Z'-name[idx]+1);
		name[idx] = 'a';
		int cnt = 0;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] == 'a')continue;
			if (name[i] == 'A') continue;
			cnt++;
		}
		if (!cnt)break;
		//조이스틱 이동
		//오른쪽으로 이동
		int ridx = idx;
		int rcnt = 0;
		while (1) {
			ridx = (ridx + 1) % name.length();
			rcnt++;
			if (name[ridx] == 'a')continue;
			if (name[ridx] != 'A')break;
		}
		int lidx = idx;
		int lcnt = 0;
		//왼쪽으로 이동
		while (1) {
			lidx = (lidx + name.length() - 1) % name.length();
			lcnt++;
			if (name[lidx] == 'a')continue;
			if (name[lidx] != 'A')break;
		}
		if (rcnt <= lcnt) {
			idx = ridx;
			answer += rcnt;
		}
		else {
			idx = lidx;
			answer += lcnt;
		}
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<solution("ABABAAAAABA");
	return 0;
}