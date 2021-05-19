#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int i = 666, n, cnt = 0;
bool flag;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

    while (cnt != n) {
        int temp = i;
        flag = false;

        while (temp != 0) {
            if (temp % 1000 == 666) {
                flag = true;
                break;
            }
            temp /= 10;
        }

        if (flag) cnt++;
        i++;
    }
    cout << i - 1;

	return 0;
}