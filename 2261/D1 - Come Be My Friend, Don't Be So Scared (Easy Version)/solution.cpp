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
   if(n<=1){
    cout<<0<<endl;
    return;
   }
   int len=n/2+n%2;
   cout<<len<<endl;
   int l=1,r=len;
   while(l<=len){
    cout<<l<<" "<<r<<endl;
    l++;
    r++;
   }
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}