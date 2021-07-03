#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(pair<int, vector<int>>a, pair<int, vector<int>>b) {
	return a.first < b.first;
}

vector<int> solution(string s) {
	vector<int> answer;
	set<int>S;
	vector<pair<int, vector<int>>>v;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '{') {
			vector<int> temp;
			int cnt = 1;
			string st;
			for (int j = i + 1; j < s.length() - 1; j++) {
				if (s[j] == ',') {
					int num = 0;
					for (int k = st.length() - 1, n = 1; k >= 0; k--,n*=10) {
						num += (st[k] - '0') * n;
					}
					temp.push_back(num);
					st.clear();
					cnt++;
					continue;
				}
				if (s[j] == '}') {
					int num = 0;
					for (int k = st.length() - 1, n = 1; k >= 0; k--, n *= 10) {
						num += (st[k] - '0') * n;
					}
					temp.push_back(num);
					st.clear();
					v.push_back({ cnt,temp });
					break;
				}
				st += s[j];
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.size(); j++) {
			if (S.count(v[i].second[j]))continue;
			else {
				answer.push_back(v[i].second[j]);
				S.insert(v[i].second[j]);
				break;
			}
		}
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	return 0;
}