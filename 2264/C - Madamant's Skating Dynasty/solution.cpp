#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
long long modpow(auto a, auto x)
{
    if(x==0)return 1;
    long long one=modpow(a,x/2);
    one=(one*one)%MOD;
    if(x&1) return (one*a)%MOD;
    else return one;
}
 
long long modinv(auto n,auto d)
{
    return (n*modpow(d,MOD-2))%MOD;
}
 
void solve(){
   long long  n;
   cin>>n;
   vector<int> a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a.begin(),a.end());
   vector<long long >suff(n,a[n-1]);
   long long  fact=1;
   for(int i=1;i<n;i++)fact=(fact*i)%MOD;
 
   for(int i=n-2;i>=0;i--)suff[i]=(suff[i+1]+a[i])%MOD;
 
   long long ans=0;
 
  // cout<<modinv(16,4)<<" "<<modpow(2,2)<<endl;
 
   for(int i=0;i<n-1;i++)
   {
       long long diff=n-1-i ;
       //( (n*(n-1)/2)%MOD - (i*(i+1)/2)%MOD )%MOD
 
       long long temp1=( (suff[i+1] - ( a[i]*diff )%MOD )%MOD +MOD)%MOD;
       //cout<<suff[i]<<" "<<temp1<<endl;
       ans= ( ans+ ( modinv(fact,n-i-1)*temp1 ) %MOD )%MOD ;
   }
   cout<<ans<<endl;;
 
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}