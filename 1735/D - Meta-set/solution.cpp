#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
vector<long long> tree;
void build(auto &a, long long  v, long long  tl, long long  tr) {
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }
    int left = 2 * v + 1;
    int right = 2 * v + 2;
    int tm = (tl + tr) / 2;
    build(a, left, tl, tm);
    build(a, right, tm + 1, tr);
    tree[v] = __gcd(tree[left], tree[right]);
}
 
long long query(int v, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return tree[v];
    if (tl > r || tr < l) return 0;
    int tm = (tl + tr) / 2;
    long long res_left = query(2 * v + 1, tl, tm, l, r);
    long long res_right = query(2 * v + 2, tm + 1, tr, l, r);
    return __gcd(res_left, res_right);
}
void update(int tl, int tr, int v, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }
    int left = 2 * v + 1;
    int right = 2 * v + 2;
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(tl, tm, left, pos, val);
    } else {
        update(tm + 1, tr, right, pos, val);
    }
    tree[v] = __gcd(tree[left], tree[right]);
}
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
 
void solve(){
int n,k;
cin>>n>>k;
vector <string> a(n);
for(int i=0;i<n;i++)
{
    string temp="";
    int  ch;
    for(int j=0;j<k;j++)
    {
        cin>>ch;
        temp.push_back(char(48+ch));
    }
    a[i]=temp;
}
 
map <string,int> f,common;
 
 
for(auto s:a)f[s]=1;//for(auto [s,cnt]:f)cout<<s<<endl;
 
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        string comi="";
        int xorr=3;
        for(int l=0;l<k;l++)
        {
 
            int x=a[i][l]-'0',y=a[j][l]-'0';char z=char( ((x==y)?x:xorr^x^y)+48);
           comi.push_back(z);
        }
       // cout<<comi<<endl;
        if(f.count(comi))
        common[comi]++;
    }
}
long long ans=0;
//for(auto [s,cnt]:common)cout<<cnt<<" test ";
for(auto [s,cnt]:common )ans+=cnt*(cnt-1)/2;
cout<<ans<<endl;
 
 
}
 
 
 
int main() {
    Atiksh
    int t;
    t=1;
    //cin>>t;
        while (t--) {
            solve();
        }
 
    return 0;
}