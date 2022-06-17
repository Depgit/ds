#include <bits/stdc++.h>
using namespace std;

template<class T> struct SegTree {
	T U = 1e9; T F(T a, T b) { return min(a,b); }
	int N; vector<T> t; SegTree() {}
	SegTree(int N) : N(N), t(4*N,U) {}
	void upd(int I, T V) { upd(I,V,1,1,N); }
	void upd(int I, T V, int i, int l, int r) {
		if(l==r) { t[i]=V; return; } int m=(l+r)/2;
		if(I<=m) upd(I,V,i*2,l,m);
		else upd(I,V,i*2+1,m+1,r);
		t[i] = F(t[i*2], t[i*2+1]); }
	T qry(int L, int R) { return qry(L,R,1,1,N); }
	T qry(int L, int R, int i, int l, int r) {
		if(L<=l && r<=R) return t[i];
		if(R<l || L>r) return U; int m=(l+r)/2;
		return F(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r)); }
};


const int sz = (1 << 18);
const int inf = 1e18;

struct st {
    vector<int> data;
    
    st() {
        data.resize(sz * 2, inf);
    }
    
    void set(int id, int val) {
        data[id + sz] = val;
        for (int i = (id + sz) / 2; i > 0; i /= 2) data[i] = min(data[i * 2], data[i * 2 + 1]);
    }
    
    int get(int l, int r, int ld = 0, int rd = sz, int id = 1) {
        if (l >= rd || r <= ld) return inf;
        if (l <= ld && rd <= r) return data[id];
        return min(get(l, r, ld, (ld + rd) / 2, id * 2), get(l, r, (ld + rd) / 2, rd, id * 2 + 1));
    }
};




template <typename T, class Function = function<T(const T &, const T &)>>
class SegmentTree {
private:
    int N;
    Function func;
    vector<T> tree;
    void _build(vector<T>& arr, int v, int l, int r){
        if(l==r) return void(tree[v] = arr[l]);
        int mid = (l+r)/2;
        _build(arr, 2*v+1, l, mid); _build(arr, 2*v+2, mid+1, r);
        tree[v] = func(tree[2*v+1], tree[2*v+2]);
    }
    T _query(int v, int l, int r, int i, int j){
        if(i>r || j<l) return 1e15;  // no overlap
        if(i<=l && r<=j) return tree[v];   // complete overlap
        int mid = (l+r)/2;
        T left = _query(2*v+1, l, mid, i, j);
        T right = _query(2*v+2, mid+1, r, i, j);
        return func(left, right);
    }
    void _update(int v, int l, int r, int i, T val){
        if(i>r || i<l) return; // no overlap
        if(l==r) return void(tree[v] = val);  // l == i  and i == r;
        int mid = (l+r)/2;
        _update(2*v+1, l, mid, i, val);
        _update(2*v+2, mid+1, r, i, val);
        tree[v] = func(tree[2*v+1], tree[2*v+2]);
    }
public:
    SegmentTree(vector<T>& ar, const Function& f) : func(f) {
        N = ar.size();
        tree.assign(4*N, 0);
        _build(ar, 0, 0, N-1);
    }
    SegmentTree(int n, const Function& f) : N(n), func(f) {
        vector<T> ar(N, 1e15);
        tree.assign(4*N, 0);
        _build(ar, 0, 0, N-1);
    }
    T query(int i, int j){ return _query(0, 0, N-1, i, j); }
    void update(int i, T val){ _update(0, 0, N-1, i, val); }
};






#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using indexed_multiset = 
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 2e5 + 10;
indexed_multiset<int> Tree[4 * N];
int lst[N];
void MargeNode(indexed_multiset<int> & a, indexed_multiset<int> & b, indexed_multiset<int> & c) {
    for (auto & child : b) a.insert(child);
    for (auto & child : c) a.insert(child);
}
void BuildTree (int ind, int l, int r) {
    if (l == r) {
        Tree[ind].insert(lst[l]);
        return;
    }
    int mid = (l + r) >> 1;
    BuildTree(2 * ind, l, mid);
    BuildTree(2 * ind + 1, mid + 1, r);
    MargeNode(Tree[ind], Tree[2 * ind], Tree[2 * ind + 1]);
}
int query(int ind, int l, int r, int l1, int r1, int value) {
    if(l1<=l && r<=r1) 
        return Tree[ind].order_of_key(value);
    if(r1<l || l1>r) return 0; 
    int m=(l+r)/2;
    return (query(2*ind,l,m,l1,r1,value) +  query(2*ind+1,m+1,r,l1,r1,value));
} 
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> lst[i];
    BuildTree(1, 0, n - 1);
    int q; cin >> q;
    while (q--) {
        int l, r, val; cin >> l >> r >> val;
        cout << query(1, 0, n - 1, l, r, val) << endl;
    }
    return 0;
}

