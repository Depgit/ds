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


