#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	double temp = 0;
	map<string, int>s1, s2;
	vector<string>all;
	//소문자 모두 대문자로 변환(비교에 용이하게 하려고)
	for (int i = 0; i < str1.length(); i++) {
		if ('a' <= str1[i] && str1[i] <= 'z') {
			str1[i] -= 32;
		}
	}
	for (int i = 0; i < str2.length(); i++) {
		if ('a' <= str2[i] && str2[i] <= 'z') {
			str2[i] -= 32;
		}
	}
	for (int i = 0; i < str1.length() - 1; i++) {
		string sub;
		for (int j = i; j < i + 2; j++) {
			if (!('A' <= str1[j] && str1[j] <= 'Z'))continue;
			else sub += str1[j];
		}
		if (sub.length() != 2)continue;
		if (s1.find(sub) == s1.end()) {//새로운 문자열인 경우
			s1.insert({ sub,1 });
			all.push_back({ sub });//전체 문자열에도 추가
		}
		else {
			int temp = s1[sub];
			s1.erase(sub);
			s1.insert({ sub,temp + 1 });
		}
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		string sub;
		for (int j = i; j < i + 2; j++) {
			if (!('A' <= str2[j] && str2[j] <= 'Z'))continue;
			else sub += str2[j];
		}
		if (sub.length() != 2)continue;
		if (s2.find(sub) == s2.end()) {
			s2.insert({ sub,1 });
			if (s1.find(sub) == s1.end())all.push_back({ sub });//전체 문자열에 없는 경우 추가
		}
		else {
			int temp = s2[sub];
			s2.erase(sub);
			s2.insert({ sub,temp + 1 });
		}
	}
	double s = 0, a = 0;
	for (int i = 0; i < all.size(); i++) {
		s += min(s1[all[i]], s2[all[i]]);
		a += max(s1[all[i]], s2[all[i]]);
	}
	if (s == 0 && a == 0)answer = 65536;
	else answer = s / a * 65536;
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution("aaabbbb", "aaaabbb");
	return 0;
}