#include <iostream>
#include <algorithm>

using namespace std;


int N, M;
int Time[10001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> Time[i];
    }
    //이분탐색을 통해 제일 마지막 인원이 타는 시간을 구함
    long long left = 0;
    long long right = 60000000000;//30*2000000000

    if (N <= M) {//전체인원수가 놀이기구 수보다  
        cout << N << '\n';
        return 0;
    }
    long long EdTime = 0;

    while (left <= right) {//적정 시간 찾기
        long long mid = (left + right) / 2;
        long long person = M;//0초에는 놀이기구 수 만큼 이미 탑승을 했으니까 그걸 더해줌
        for (int i = 0; i < M; i++) {
            person += mid / Time[i];
        }

        if (person >= N) {//탑승한 사람수가 전체 인원수 보다 많은경우 >> 적정시간을 줄여줘야함
            EdTime = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    //적정 시간을 찾은 경우 해당시간 -1 시간까지의 모든 인원수를 더해줌
    long long person = M;
    for (int i = 0; i < M; i++) {
        person += ((EdTime - 1) / Time[i]);
    }

    //적정 시간에서 탑승하는 사람을 더해준다
    for (int i = 0; i < M; i++) {

        if (EdTime % Time[i] == 0)person++;
        if (person == N) {
            cout << i + 1 << '\n';
            break;
        }

    }
    return 0;
}