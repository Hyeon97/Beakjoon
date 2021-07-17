#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int ans = 0;

	while (n) {
		if (n % 2)ans++;
		n /= 2;
	}

    return ans;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution(5000);
	return 0;
}