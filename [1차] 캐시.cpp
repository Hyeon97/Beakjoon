#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	if (!cacheSize)return cities.size() * 5;
	vector<string>use;
	bool flag = true;
	for (int i = 0; i < cities.size(); i++) {
		flag = true;
		for(int j=0; j<cities[i].length(); j++) cities[i][j] = tolower(cities[i][j]);
		for (int j = 0; j < use.size(); j++) {
			if (!use[j].compare(cities[i])) {
				answer += 1;
				use.erase(use.begin() + j);
				flag = false;
				break;
			}
		}
		if (flag)answer += 5;
		use.push_back(cities[i]);
		if (use.size() >cacheSize) {
			use.erase(use.begin()+0);
		}
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" });
	return 0;
}