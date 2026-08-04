 
#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC target ("sse,sse2,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define dbg(args...) 42;
    #define endl "
"
#endif
 
// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second
 
using lli = long long int;
using mytype = long double;
using ii = pair<lli,lli>;
using vii = vector<ii>;
using vi = vector<lli>;
 
template <class T>
using ordered_set =  __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.
 
// namespace Re = std::ranges;
// namespace Ve = std::ranges::views;
 
const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"
";
}
 
const lli INF = 0xFFFFFFFFFFFFFFFLL;
const lli SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}
 
class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};
 
void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}
 
void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}
 
bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
 
using t3 = array<lli,3>;
using t6 = array<lli,6>;
 
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// Ve::iota(1, 6) | Ve::transform([](int x) { return x * 2; }) | Ve::reverse | Ve::take(3)
lli T=1;
cin>>T;
while(T--)
{
    lli n,m,h;
    cin>>n>>m>>h;
    set<lli> horse;
    while(h--){
        lli k;
        cin>>k;
        k--;
        horse.insert(k);
    }
    dbg(horse);
    vector<vii> e(n);
    while(m--){
        lli u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        e[u].eb(v,w);
        e[v].eb(u,w);
    }
    dbg(e);
    auto run=[&](const lli src,vector<t6> &dist)->void{
        dbg("run",src);
        priority_queue<t3> pq;
        if(src)
            pq.push({0,src,-3});
        else
            pq.push({0,src,-1});
 
        if(horse.count(src))
            pq.push({0,src,src});
 
        dist.clear();
        dist.resize(n,t6{INF,-2,INF,-2,INF,-2});
 
        while(!pq.empty()){
            const auto tp=pq.top();pq.pop();
            const lli u=tp[1],hr=tp[2],d=-tp[0];
            dbg(u,d,hr);
            bool cont = true;
            for(lli j=0;j<3;j++){
                if(dist[u][2*j+1]==hr){
                    cont=false;
                    break;
                }
            }
 
            if(!cont)
                continue;
 
            if(dist[u][5]!=-2)
                continue;
 
            cont = false;
            for(lli j=0;j<3;j++){
                if(dist[u][2*j+1]==-2){
                    dist[u][2*j]=d;
                    dist[u][2*j+1]=hr;
                    cont = true;
                    break;
                }
            }
 
            if(!cont)
                continue;
 
            for(const auto &v:e[u]){
                if(hr==-1||hr==-3){
                    pq.push({-d-v.Y,v.X,hr});
                    if(horse.count(v.X))
                        pq.push({-d-v.Y,v.X,v.X});
                    continue;
                }
                pq.push({-d-(v.Y/2),v.X,hr});
            }
        }
    };
 
    vector<t6> d1,dn;
    run(0,d1);
    run(n-1,dn);
 
    if(d1[n-1][0]>=INF){
        cout<<-1<<endl;
        continue;
    }
 
    lli ans = INF;
 
    for(lli u=0;u<n;u++){
        for(lli j=0;j<3;j++)
            for(lli k=0;k<3;k++){
                if(d1[u][2*j+1]==dn[u][2*k+1])
                    continue;
                const lli cur=max(d1[u][2*j],dn[u][2*k]);
                // if(ans>cur){
                    // dbg(u,cur,d1[u][2*j],d1[u][2*j+1],dn[k][2*j],dn[u][2*k+1]);
                // }
                ans=min(ans,cur);
 
            }
    }
 
    cout<<ans<<endl;
 
}   aryanc403();
    return 0;
}