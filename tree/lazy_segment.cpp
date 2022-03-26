#include <bits/stdc++.h>
using namespace std;

template <typename T, class Function = function<T(const T &, const T &)>>
class SegmentTree {
private:
    int N;
    Function func;
    vector<T> tree, lazy;
    void push(int v){
        if(lazy[v]) return;
        tree[2*v+1] = lazy[v];
        lazy[2*v+1] = lazy[v];
        tree[2*v+2] = lazy[v];
        lazy[2*v+2] = lazy[v];
        lazy[v] = 0;
    }
    void _build(vector<T>& arr, int v, int tl, int tr){
        if(tl==tr) return void(tree[v] = arr[tl]);
        int tm = (tl+tr)/2;
        _build(arr, 2*v+1, tl, tm); _build(arr, 2*v+2, tm+1, tr);
        tree[v] = func(tree[2*v+1], tree[2*v+2]);
    }
    T _query(int v, int tl, int tr, int l, int r){
        if(r<tl || l>tr || l>r) return 0;
        if(tl>=l && tr<=r) return tree[v];
        push(v);
        int tm = (tl+tr)/2;
        T left = _query(2*v+1, tl, tm, l, r);
        T right = _query(2*v+2, tm+1, tr, l, r);
        return func(left, right);
    }
    void _update(int v, int tl, int tr, int l, int r, T addend){
        if(r<tl || l>tr || l>r) return;
        if(tl>=l && tr<=r){
            tree[v] = addend;
            lazy[v] = addend;
        }else{
            push(v);
            int tm = (tl+tr)/2;
            _update(2*v+1, tl, tm, l, r, addend);
            _update(2*v+2, tm+1, tr, l, r, addend);
            tree[v] = func(tree[2*v+1], tree[2*v+2]);
        }
    }
    int get(int v, int tl, int tr, int i){
        if(tr<i || tree[v]==0) return 0;
        if(tr==tl) return tl;
        push(v);
        int tm = (tl+tr)/2;
        int j = get(2*v+1, tl, tm, i);
        if(j) return j;
        return get(2*v+2, tm+1, tr, i);
    }
public:
    SegmentTree(vector<T>& ar, const Function& f) : func(f) {
        N = ar.size();
        tree.resize(4*N);
        lazy.resize(4*N, 1);
        _build(ar, 0, 0, N-1);
    }
    T query(int i, int j){ return _query(0, 0, N-1, i, j); }
    void update(int i, int j, T add){ _update(0, 0, N-1, i, j, add); }
    int get(int i){ return get(0, 0, N-1, i); }
};


namespace ST {
    vector<int> Black, lazy;

    void build(int n, int l, int r){
        if(l > r) return;
        Black[n] = r-l+1;
        if(l == r) return;

        int mid = (l+r)/2;
        build(2*n, l, mid);
        build(2*n+1, mid+1, r);
    }

    void init(int N){
        Black.resize(4*N);
        lazy.resize(4*N);
    
        build(1, 0, N-1);
    }

    void lazyUpdate(int n, int l, int r){
        if(lazy[n] == 0) return;
        Black[n] = (r-l+1)-Black[n];
    
        if(l < r){
            lazy[2*n] ^= 1;
            lazy[2*n+1] ^= 1;
        }
        lazy[n] = 0;
    }

    void flip(int n, int l, int r, int L, int R){
        lazyUpdate(n, l, r);
        if(r < L or R < l) return;
        if(L <= l and r <= R){
            lazy[n] ^= 1;
            lazyUpdate(n, l, r);
            return;
        }

        int mid = (l+r)/2;
        flip(2*n, l, mid, L, R);
        flip(2*n+1, mid+1, r, L, R);
        Black[n] = Black[2*n]+Black[2*n+1];
    }

    int query(int n, int l, int r, int L, int R){
        lazyUpdate(n, l, r);
        if(r < L or R < l) return 0;
        if(L <= l and r <= R) return Black[n];

        int mid = (l+r)/2;
        return query(2*n, l, mid, L, R)+
            query(2*n+1, mid+1, r, L, R);
    }
};


