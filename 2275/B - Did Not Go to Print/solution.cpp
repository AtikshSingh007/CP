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
  string s;
  cin>>s;
  vector<int> vec,f(n+1,1);
  f[0]=0;
  for(int i=1;i<=n;i++)
  {
      if(s[i-1]=='1')vec.push_back(i);
      else if(s[i-1]=='2')
      {
          if(vec.size())
          {
              f[vec.back()]=0;
              vec.pop_back();
          }
          else
            f[i]=0;
      }
      else
      {
          f[i]=0;
      }
  }
 
  int cnt=accumulate(f.begin(),f.end(),0);
 
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++)
    if(f[i]==1)
    cout<<i<<" ";
    cout<<endl;
 
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