#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// order_of_key (k) -> Number of items less than k 
// find_by_order(k) -> index of Kth element
using namespace __gnu_pbds;
template <typename T> using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long 
using namespace std;
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
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {for (auto& i : v) os << i << " ";return os;}
template<typename T> istream& operator>>(istream& in, vector<T>& v) {for (auto& e : v) in >> e;return in;}
template<typename T> istream& operator>>(istream& in, vector<vector<T>>& v) {for (auto& row : v) in >> row;return in;}
auto sum(){return 0;}
template<typename T,typename... Args> auto sum(T a, Args... args) { return a + sum(args...); }

// // function 
const int MOD = 998244353;
// const int MOD =  1e9+7;
#define ll long long
// #define vl vector<ll>
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
struct _in {template<class T> operator T() {T x;cin >> x;return x;}} in;


const int N = 2e5+5,inf = 1e18+10,M = 1e7+5;
int n,l,m,x,u,v,k,p,q,i,j,r,y;
string s,t;
int ans;
int res;

int test = 1;

void solve(){
    
}


signed main(){
    fast;
    int t=1;
    cout.precision(20);
    cin>>t;
    // f();
    // g();
    while(t--){
        solve();
    }
    return 0;
}   