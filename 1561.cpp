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
    //�̺�Ž���� ���� ���� ������ �ο��� Ÿ�� �ð��� ����
    long long left = 0;
    long long right = 60000000000;//30*2000000000

    if (N <= M) {//��ü�ο����� ���̱ⱸ ������  
        cout << N << '\n';
        return 0;
    }
    long long EdTime = 0;

    while (left <= right) {//���� �ð� ã��
        long long mid = (left + right) / 2;
        long long person = M;//0�ʿ��� ���̱ⱸ �� ��ŭ �̹� ž���� �����ϱ� �װ� ������
        for (int i = 0; i < M; i++) {
            person += mid / Time[i];
        }

        if (person >= N) {//ž���� ������� ��ü �ο��� ���� ������� >> �����ð��� �ٿ������
            EdTime = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    //���� �ð��� ã�� ��� �ش�ð� -1 �ð������� ��� �ο����� ������
    long long person = M;
    for (int i = 0; i < M; i++) {
        person += ((EdTime - 1) / Time[i]);
    }

    //���� �ð����� ž���ϴ� ����� �����ش�
    for (int i = 0; i < M; i++) {

        if (EdTime % Time[i] == 0)person++;
        if (person == N) {
            cout << i + 1 << '\n';
            break;
        }

    }
    return 0;
}