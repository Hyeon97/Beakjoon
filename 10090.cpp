#include <iostream>
#include <algorithm>
#define MAX_N 1000000
using namespace std;
int seg[4 * MAX_N], x, n;
long long r;
int update(int pos, int node, int x, int y) {
    if (pos < x || y < pos)return seg[node];
    if (x == y)return seg[node] += 1;
    int mid = (x + y) >> 1;
    return seg[node] = update(pos, node * 2, x, mid) + update(pos, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
    if (y < lo || hi < x)
        return 0;
    if (lo <= x && y <= hi)
        return seg[node];
    int mid = (x + y) >> 1;
    return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        r += (long long)(x - 1 - query(1, x - 1, 1, 1, n));
        update(x, 1, 1, n);
    }
    printf("%lld\n", r);
    return 0;
}
