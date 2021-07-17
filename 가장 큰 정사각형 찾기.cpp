#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int map[1001][1001];
int solution(vector<vector<int>> board)
{
	int answer = 0;
	int Y = board.size();
	int X = board[0].size();
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			if (board[y-1][x-1]) {
				map[y][x] = min(map[y - 1][x], min(map[y][x - 1], map[y - 1][x - 1]))+1;
				answer = max(answer, map[y][x]);
			}
			else {
				map[y][x] = 0;
			}
		}
	}
	
	return answer*answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution({ {1} });
	return 0;
}