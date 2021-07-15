#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	answer.resize(arr1.size());
	for (int i = 0; i < arr1.size(); i++) {
		for (int k = 0; k < arr2[0].size(); k++) {
			int temp = 0;
			for (int j = 0; j < arr1[i].size(); j++) {
				temp += arr1[i][j] * arr2[j][k];
			}
			answer[i].push_back(temp);
		}
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ {1, 4}, {3, 2}, {4, 1} }, { {1,2}, {3, 4} });
	return 0;
}