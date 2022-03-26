#include "bits/stdc++.h"
using namespace std;

template <typename T, class Function = function<T(const T &, const T &)>>
class SparseTable{
private:
    int N;
    Function func;
    vector<vector<T>> Table;
public:
    SparseTable(vector<T>& arr, const Function& f) : func(f){
        N = int(arr.size());
		Table.resize(N);
        int max_lg = 32 - __builtin_clz(N);
		for (int i = 0; i < N; i++){
			Table[i].resize(max_lg);
			Table[i][0] = arr[i];
		}
		for (int j = 1; j <= max_lg; j++){
			for (int i = 0; (i + (1 << j) - 1) < N; i++)
				Table[i][j] = func(Table[i][j - 1], Table[i + (1 << (j - 1))][j - 1]);
		}
	}
	T query(int i, int j){
        	assert(0 <= i && i <= j && j <= N - 1);
        	int lg = 32 - __builtin_clz(j - i + 1) - 1;
		return func(Table[i][lg], Table[j - (1 << lg) + 1][lg]);
	}
};