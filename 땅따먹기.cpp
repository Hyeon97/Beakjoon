#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
	for (int i = 1; i < land.size(); i++) {
		land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
		land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
		land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
		land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
	}

	return max(land[land.size() - 1][0], max(land[land.size() - 1][1], max(land[land.size() - 1][2], land[land.size() - 1][3])));
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ {1, 4}, {3, 2}, {4, 1} }, { {1,2}, {3, 4} });
	return 0;
}