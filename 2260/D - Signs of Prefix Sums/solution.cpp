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
string s ;
cin>>s;
for(int i=1;i<n;i++)
    if(s[i]=='0' && s[i-1]=='0')
{
    cout<<-1<<endl;
    return ;
}
if(s[0]=='0')
{
    cout<<-1<<endl;
    return ;
}
 
int ans=1;vector<int> a(n);
 
int pl=0,mi=0;
for(int i=0;i<n;i++)
{
    if(s[i]=='+')
    {
        pl++;
        mi=0;
    }
    else if(s[i]=='-')
    {
        mi++;
        pl=0;
    }
 
    if( s[i]=='0' &&  (( (mi%2)==0 && mi>0) || ( (pl%2)==0 && pl>0))  ){
        ans=2;
        mi=0;
        pl=0;
    }
    if(s[i]=='0')
    {
        mi=0;
        pl=0;
    }
 
}
for(int i=1;i<n;i++)
    if( (s[i]=='+' && s[i-1]=='-') || (s[i]=='-' && s[i-1]=='+') )
        ans=2;
 
for(int i=3;i<n;i++)
{
    if( (s[i-3]=='-' && s[i-2]=='+' && s[i-1]=='+' && s[i]=='-' ) || (s[i-3]=='+' && s[i-2]=='-' && s[i-1]=='-' && s[i]=='+' ) )ans=3;
}
cout<<ans<<endl;
 
}
 
int main() {
    Atiksh
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
 
    return 0;
}