#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector <int >a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    set <int> st,en;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
 
    if(n<(2*m))
    {
        cout<<"NO"<<endl;
        return ;
    }
    for(int i=0;i<m;i++)st.insert(a[i]);
    for(int i=m;i<n;i++)en.insert(a[i]);
 
 
    for(int i=0;i<m;i++)
    {
        auto l=st.begin(),r=en.upper_bound(b[i]);
       // cout<<*l<<" ofaj "<<*r<<endl;
        if( r!=en.end() && l!=st.end() && (*r)>b[i] && (*l)<b[i])
        {
            st.erase(l);
            en.erase(r);
        }
        else{
            cout<<"NO"<<endl;
        return;
            }
    }
    cout<<"YES"<<endl;
}
 
int main() {
    Atiksh
    int t;
    t=1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}