 
// nodes will be 1-indexed like in the problem
vector<int> adj[MAX_N + 1];
 
set<int> colors[MAX_N + 1];
int dist[MAX_N + 1];
 
void dfs(int curr, int parent) {
	for (int n : adj[curr]) {
		if (n != parent) {
			dfs(n, curr);
			// make x the larger set always
			if (colors[curr].size() < colors[n].size()) {
				swap(colors[curr], colors[n]);
			}
			for (int item : colors[n]) {
				colors[curr].insert(item);
			}
		}
	}
	dist[curr] = colors[curr].size();
}