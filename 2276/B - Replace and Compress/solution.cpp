#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 1;
        if (s.find("010") != string::npos || s.find("101") != string::npos)
            ans++;
        if (s.find("000") != string::npos || s.find("111") != string::npos)
            ans++;
        cout << ans << "
";
    }
    return 0;
}