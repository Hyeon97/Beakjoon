#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
	a--; b--;
	while (a != b) {
		a /= 2;
		b /= 2;
		answer++;
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(8,4,7);
	return 0;
}
