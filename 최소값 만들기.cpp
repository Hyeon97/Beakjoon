#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(),greater<int>());
    for (int i = 0; i < A.size(); i++) {
        answer += (A[i] * B[i]);
    }

    return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
    solution({ 1,2 }, {4,3});
	return 0;
}