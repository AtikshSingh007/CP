#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> b;vector<int> ans(32);
    ans[0]=a.back()-a[0];
    for(int m=0;m<32;m++)
    {
        vector<int> temp;
    for(int i=0;i<n;i++)
    {
 
        for(int j=i+1;j<n;j++)
        {
            temp.push_back(a[i]^a[j]);
        }
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
        a[i]=temp[i];
    ans[m+1]=a.back()-a[0];
    }
    while(q--)
    {
        int x;
        cin>>x;
        if(x>31)cout<<0<<endl;
        else cout<<ans[x]<<endl;
 
    }
 
}
 
int main() {
    Atiksh
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}