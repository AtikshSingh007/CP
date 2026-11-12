#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
 
 
void solve(){
int n;
cin>>n;
string s;
cin>>s;
int c=(s[0]=='B')?1:0;
for(int i=1;i<n;i++)
    if(s[i]==s[i-1])c++;
cout<<c<<endl;
}
 
int main(){
    Atiksh
    //fill_primes();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}