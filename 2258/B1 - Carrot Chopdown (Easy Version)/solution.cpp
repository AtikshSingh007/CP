#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int N, M;
    std::cin >> N >> M;
 
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
 
    std::vector<int> sf(M + 2);
    for (int i = 0; i < N; ++i) {
        sf[A[i]] += 1;
    }
 
    for (int i = M; i >= 1; --i) {
        sf[i - 1] += sf[i];
    }
 
    i64 ans = 0;
    for (int x = 1; x <= M; ++x) {
        i64 now = sf[x];
        if (x * 2 <= M) now += sf[2 * x] - sf[2 * x + 1];
        ans = std::max(ans, now);
    }
    std::cout << ans << '
';
    
    return;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int TT = 1; std::cin >> TT;
    for (int i = 1; i <= TT; ++i) {
        solve();
    }
 
    return 0;
}