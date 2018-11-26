#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?â��\nâ��:â�� â��)
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?â��\nâ��:â�� â��)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
#define PI (acos(-1.0))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define dist(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int N=3e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
struct node
{
    int l,r,val;
    node(){l=r=0,val=2e9;}
    node(int _l,int _r,int _val){
        l=_l,r=_r,val=_val;
    }
}t[20*N];
int root[N],cnt;
void build(int cur,int b,int e)
{
    if(b==e){
        t[cur]=node(0,0,2e9);
        return ;
    }
    int left,right,mid=(b+e)/2;
    t[cur].l=left=++cnt;
    t[cur].r=right=++cnt;
    build(left,b,mid);
    build(right,mid+1,e);
    t[cur].val=max(t[left].val,t[right].val);
}
void upd(int pre,int cur,int b,int e,int i,int v)
{
    if(b>e) return;
    if(i<b||i>e) return;
    if(b==e){
        t[cur].val=min(t[pre].val,v);
        return;
    }
    int left,right,mid=(b+e)/2;
    if(i<=mid){
        t[cur].r=right=t[pre].r;
        t[cur].l=left=++cnt;
        upd(t[pre].l,t[cur].l,b,mid,i,v);
    }
    else{
        t[cur].l=left=t[pre].l;
        t[cur].r=right=++cnt;
        upd(t[pre].r,t[cur].r,mid+1,e,i,v);
    }
    t[cur].val=max(t[left].val,t[right].val);
}
int query(int cur,int b,int e,int i,int j)
{
    if(b>j||e<i) return 0;
    if(b>=i&&e<=j) return t[cur].val;
    int mid=(b+e)/2;
    return max(query(t[cur].l,b,mid,i,j),query(t[cur].r,mid+1,e,i,j));
}
struct seg
{
    int l,r,p;
    seg(){}
    bool operator < (const seg& x) const
    {
        return l<x.l;
    }
}a[N];
int main()
{
    fast;
    int i,j,k,n,m,t,l,que,r,p,q;
    cin>>n>>que>>k;
    for(i=1;i<=k;i++) cin>>a[i].l>>a[i].r>>a[i].p;
    sort(a+1,a+k+1);
    root[k+1]=++cnt;
    build(root[k+1],1,n);
    for(i=k;i>=1;i--){
        root[i]=++cnt;
        upd(root[i+1],root[i],1,n,a[i].p,a[i].r);
    }
    while(que--){
        cin>>p>>q>>l>>r;
        seg x;
        x.l=l-1;
        x.r=2e9;
        x.p=2e9;
        int idx=UB(a+1,a+k+1,x)-a;
        assert(idx>=1&&idx<=k+1);
        int mn=query(root[idx],1,n,p,q);
        if(mn<=r) cout<<"yes\n";
        else cout<<"no\n";
        cout.flush();
    }
    return 0;
}
