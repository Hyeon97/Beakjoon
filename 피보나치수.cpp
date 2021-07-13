#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int fivo[100000];
    fivo[0] = 0; fivo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fivo[i] = (fivo[i - 1] + fivo[i - 2]) % 1234567;
    }
    return fivo[n];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solution(3);
    return 0;
}