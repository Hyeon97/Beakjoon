#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(int n, int a, int b)
{
    int answer = 0;
	if (a < b) {
		int temp = b;
		a = b;
		b = temp;
	}
	int G = 0;
	while (b) {
		G = a % b;
		a = b;
		b = G;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(8,4,7);
	return 0;
}