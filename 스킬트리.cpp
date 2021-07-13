#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	map<char, int>m;
	for (int i = 0; i < skill.length(); i++) {
		m.insert({ skill[i],i });
	}
	for (int i = 0; i < skill_trees.size(); i++) {
		int last = -1;
		bool flag = true;
		for (int j = 0; j < skill_trees[i].length(); j++) {
			if (m.find(skill_trees[i][j]) == m.end())continue;//��ųƮ���� �ƴ� ���ڴ� ����
			else {
				if (m[skill_trees[i][j]] - last != 1) {
					flag = false;
					break;
				}
				last = m[skill_trees[i][j]];
				if (last == skill.length()-1)break;//��ųƮ�� ��� �� Ȯ���Ѱ�� �ٷ�����
			}
		}
		if (flag)answer++;
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
	return 0;
}