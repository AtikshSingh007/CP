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
 
long long ans=0;
int n;
vector <vector<int>> adj;
vector <int> clr;
 
int c1=0,c2=0,pos;
 
void dfs(int node)
{
 
    if(node<n)
    {
        if(clr[node]==1)c1++;
        else c2++;
    }
    int nxtcolor=clr[node]^1;
    for(auto nbr:adj[node])
    {
        if(clr[nbr]==-1)
        {
            clr[nbr]=nxtcolor;
            dfs(nbr);
        }
        else
            if(clr[nbr]!=nxtcolor)
            {
                pos=0;
            }
    }
 
}
 
void solve() {
    int m;
    cin>>n>>m;
    adj.assign(n+m,vector<int> ());
    clr.assign(n+m,-1);
    int fake=n;
    ans=0;pos=1;
    for(int i=0;i<m;i++)
    {
        int u,v;string role;
        cin>>u>>v>>role;
        if(role=="imposter"){
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        }
        else
        {
            adj[u-1].push_back(fake);
            adj[fake].push_back(u-1);
            adj[v-1].push_back(fake);
            adj[fake].push_back(v-1);
            fake++;
        }
    }
 
    for(int i=0;i<n;i++)
    {
       if(clr[i]!=-1)continue;
       clr[i]=1;
       c1=0,c2=0;
       dfs(i);
       ans+=max(c1,c2);
    }
    if(pos)
    cout<<ans<<endl;
    else
        cout<<-1<<endl;
 
 
}
 
int main() {
    Atiksh
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}