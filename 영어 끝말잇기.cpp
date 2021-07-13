#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//规过1
vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	map<string, int>m;
	m.insert({ words[0], 1 });
	for (int i = 1; i < words.size(); i++) {
		if (m.find(words[i]) != m.end() || words[i][0] != words[i - 1][words[i - 1].length() - 1]) {
			return { i % n + 1, i / n + 1 };
		}
		m.insert({ words[i], 1 });
	}
	return { 0,0 };
}

//规过2
vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<int> w[10];
	map<string, int>m;
	m.insert({ words[0], 1 });
	w[0].push_back(1);
	bool flag = true;
	for (int i = 1, j = 1; i < words.size(); i++, ++j %= n) {
		if (m.find(words[i]) != m.end() || words[i][0] != words[i - 1][words[i - 1].length() - 1]) {
			flag = false;
			answer.push_back(j + 1);
			answer.push_back(w[j].size() + 1);
			break;
		}
		m.insert({ words[i], 1 });
		w[j].push_back(1);
	}
	if (flag) {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });
	return 0;
}