#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int W = brown + yellow;
    for (int i = W / 2; i > 0; i--){
        if (W % i == 0){
            int a = i, b = W / i;
            if ((a - 2) * (b - 2) == yellow){
                answer.push_back(a);
                answer.push_back(b);
                break;
            }
        }
    }
    return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(3,3);
	return 0;
}