#include "bits/stdc++.h"
using namespace std;

#define int long long 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vl vector<int>
#define vvl vector<vl>
#define vs vector<string>
#define pl pair<int,int>
#define vpl vector<pl>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define For(i, a, b) for (int i = (a); i < (b); ++i)
#define repr(i,x,y) for (int i = (x); i >= (y); --i)
int mod(int x,int MOD){if(x>MOD)x-=MOD;return x;}
int _ceil(int x,int y){return x/y+(x%y!=0);}
void wrt() { cout << "\n"; return;}template<typename T1, typename... T2>void wrt(T1 x, T2... args){((cout << x << ' '), wrt(args...));}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto& i : v) os << i << " ";return os;}
template<typename T> istream& operator>>(istream& in, vector<T>& v) {for (auto& e : v) in >> e;return in;}
template<typename T> istream& operator>>(istream& in, vector<vector<T>>& v) {for (auto& row : v) in >> row;return in;}
// function 
// const int MOD = 998244353;
const int MOD =  1e9+7;
#define ll long long
template<class T> ll _sum(vector<T>& arr) { return accumulate(all(arr), 0ll); }
template<class T> bool _min(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool _max(T &a, T b) { return a < b ? (a = b, true) : false; }
ll _bits(ll x) { ll cnt = 0; while(x>0) { cnt++; x>>=1; } return cnt; }
ll _setbits(ll x) { ll cnt = 0; while(x>0) { if(x&1) cnt++; x>>=1; } return cnt;}
ll _gcd(ll a, ll b) { return (b == 0) ? (a) : (_gcd(b, a %= b)); }
ll _lcm(ll a, ll b) { if (a < b) swap(a, b); return a / _gcd(a, b) * b; }
ll _add(ll x, ll y) { x %= MOD, y %= MOD; return (x + y) % MOD; }
ll _sub(ll x, ll y) { x %= MOD, y %= MOD; return (x - y + MOD) % MOD; }
ll _mul(ll x, ll y) { x %= MOD, y %= MOD; return (x * 1ll * y) % MOD; }
ll _pow(ll x, ll y) { if (y == 0) return 1; else if (y % 2 == 0){ 
ll _tmp=_pow(x, y / 2); return _mul(_tmp, _tmp);} else return _mul(x, _pow(x, y - 1));}
ll _inv(ll p) { return _pow(p, MOD - 2); }
ll _div(ll x, ll y) { x %= MOD, y %= MOD; return _mul(x, _inv(y)); }
ll _nCr(ll n, ll r, vl & fact){if(n<r)return 0; return _mul(fact[n], _inv(_mul(fact[r], fact[n - r])));}
// end 

const int N = 1e6+5,inf = 1e18+2;
int n,l,m,x,u,v,k,p,q,i,j,r,y;
string s,t;
int ans;
int res;


namespace st{
    vl tree,lazy;
    void build(int n,int l,int r){
        if(l>r)return;
        tree[n]=r-l+1;
        if(l==r)return;
        int mid = (l+r)/2;
        build(2*n,l,mid);
        build(2*n+1,mid+1,r);
    }
    void init(int N){
        tree.resize(4*N);lazy.resize(4*N);
        build(1,0,N-1);
    }
    void lazyprop(int n,int l,int r){
        if(lazy[n]==0)return;
        tree[n] = (r-l+1)-tree[n];
        if(l<r){
            lazy[2*n]^=1;
            lazy[2*n+1]^=1;
        }
        lazy[n]=0;
    }
    void updation(int n,int l,int r,int ql,int qr){
        lazyprop(n,l,r);
        if(qr<l || ql>r)return;
        if(ql<=l && qr>=r){
            lazy[n]^=1;
            lazyprop(n,l,r);
            return;
        }
        int mid = (l+r)/2;
        updation(2*n,l,mid,ql,qr);
        updation(2*n+1,mid+1,r,ql,qr);
        tree[n] = tree[2*n] + tree[2*n+1];
    }
    int query(int n,int l,int r,int ql,int qr){
        lazyprop(n,l,r);
        if(l>r || ql>r || qr<l)return 0;
        if(ql<=l && qr >= r)return tree[n];
        int mid = (l+r)/2;
        return query(2*n,l,mid,ql,qr) + query(2*n+1,mid+1,r,ql,qr);     
    }
};

using namespace st;

int timer;
vl g[N],tin,tout;

void dfs(int u, int p){
    tin[u] = timer++;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    tout[u] = timer-1;
}

void solve(){
    cin>>n;
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    rep(i,n-1){
        cin>>u>>v;
        u--,v--;
        g[u].pb(v),g[v].pb(u);
    }
    timer=0;
    dfs(0,0);
    // cout<<tin<<endl<<tout<<endl;
    init(n);
    cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==1){
            cin>>u>>v;u--,v--;
            if(tin[u]>tin[v])swap(u,v);
            int b1 = query(1,0,n-1,tin[v],tout[v]);
            int b2 = query(1,0,n-1,0,n-1)-b1;
            wrt(b1*b2);
        }else{
            cin>>u;u--;
            updation(1,0,n-1,tin[u],tout[u]);
        }
    }
}



signed main(){
    fast;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    // f();
    while(t--){
        solve();
    }
    return 0;
}   