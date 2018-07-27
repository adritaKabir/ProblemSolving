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

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
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
#define inf 1e18
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
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
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
const int mxn=1e6+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
int type[mxn],a[mxn],b[mxn];
bool ret[mxn],ans[mxn];
bool dfs(int i)
{
    int k=type[i];
    if(k==1) return ret[i]=a[i];
    if(k==2) return ret[i]=!dfs(a[i]);
    if(k==3) return ret[i]=dfs(a[i])&dfs(b[i]);
    if(k==4) return ret[i]=dfs(a[i])|dfs(b[i]);
    if(k==5) return ret[i]=dfs(a[i])^dfs(b[i]);
}
//return change hobe jodi ith node er value change hoy
void yo(int i)
{
    int k=type[i];
    if(k==1){
        ans[i]=1;
        return;
    }
    if(k==2) yo(a[i]);//1,0
    if(k==3){
        if(ret[a[i]]&&ret[b[i]]) yo(a[i]),yo(b[i]);//1 1
        else if(ret[a[i]]&&!ret[b[i]]) yo(b[i]);//1 0
        else if(!ret[a[i]]&&ret[b[i]]) yo(a[i]);//0 1
    }
    if(k==4){
        if(!ret[a[i]]&&!ret[b[i]]) yo(a[i]),yo(b[i]);//0 0
        else if(ret[a[i]]&&!ret[b[i]]) yo(a[i]);//1 0
        else if(!ret[a[i]]&&ret[b[i]]) yo(b[i]);//0 1
    }
    if(k==5){
        //1 1,1 0,0 1,0 0 in all way
        yo(a[i]);
        yo(b[i]);
    }
}
int main()
{
    fast;
    int i,j,k,n,m,t;
    string s;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s>>a[i];
        if(s=="IN") type[i]=1;
        else if(s=="NOT") type[i]=2;
        else{
            cin>>b[i];
            if(s=="AND") type[i]=3;
            else if(s=="OR") type[i]=4;
            else type[i]=5;
        }
    }
    dfs(1);
    yo(1);
    for(i=1;i<=n;i++) if(type[i]==1) cout<<(ret[1]^ans[i]);
    cout<<nl;
    return 0;
}
