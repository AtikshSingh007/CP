#include <bits/stdc++.h>
using namespace std;
 
int bitLength(long long x) {
    int cnt = 0;
    while (x > 0) {
        cnt++;
        x >>= 1;
    }
    return cnt;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
 
        if (n == 1) {
            if (k == 1) {
                cout << "YES
" << 0 << "
";
            } else {
                cout << "NO
";
            }
            continue;
        }
 
        k ^= n;
        if (bitLength(k) > bitLength(n - 1)) {
            cout << "NO
";
            continue;
        }
 
        vector<long long> s;
        if (0 < k && k <= n - 1) {
            s.push_back(k);
        } else if (k) {
            s.push_back(n - 1);
            s.push_back((n - 1) ^ k);
        }
        s.push_back(0);
 
        unordered_set<long long> inS(s.begin(), s.end());
 
        vector<long long> a = s;
        for (long long i = 0; i < n; i++) {
            if (inS.find(i) == inS.end()) {
                a.push_back(i);
            }
        }
 
        cout << "YES
";
        for (int i = (int)a.size() - 1; i >= 0; i--) {
            cout << a[i];
            if (i > 0) cout << ' ';
        }
        cout << "
";
    }
    return 0;
}