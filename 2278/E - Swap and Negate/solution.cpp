#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve() {
  int n;
  cin>>n;
  vector<long long > aa(n);
  for(int i=0;i<n;i++)cin>>aa[i];
  int odd=(n)/2,even=(n+1)/2;
  vector<pair<long long ,long long >> a;
  for(int i=0;i<n;i++)a.push_back(make_pair(aa[i],i));
 
  sort(a.begin(),a.end(),[](auto x,auto y){
       return abs(x.first)>abs(y.first);
       });
 
  long long ans=0;
  for(int j=0;j<n;j++)
  {
     // cout<<a[j].first<<" "<<a[j].second<<" "<<odd<<" "<<even<<" sum ";
      int i=a[j].second;
      if(i&1)
      {
          if(a[j].first>0)
          {
              if(odd>0){
              odd--;
              ans+=a[j].first;
              }
              else {
              even--;
              ans-=a[j].first;
              }
          }
          else if(a[j].first<0)
          {
              if(even>0)
              {
                  even--;
                  ans+=abs(a[j].first);
              }
              else{
                odd--;
                ans-=abs(a[j].first);
              }
          }
 
      }
      else
      {
          if(a[j].first>0)
          {
              if(even>0){
              even--;
              ans+=a[j].first;
              }
              else{
              odd--;
              ans-=a[j].first;
              }
          }
          else if(a[j].first<0)
          {
              if(odd>0)
              {
                  odd--;
                  ans+=abs(a[j].first);
              }
              else{
                even--;
                ans-=abs(a[j].first);
              }
          }
 
      }
     // cout<<ans<<endl;
  }
  cout<<ans<<endl;
 
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