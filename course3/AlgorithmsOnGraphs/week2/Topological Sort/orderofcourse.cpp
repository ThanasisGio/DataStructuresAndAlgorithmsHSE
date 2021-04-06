#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &ordering, int x) {
  used[x] = true;
  for (int i = 0; i < adj[x].size(); i++) {
	if(!used[adj[x][i]])
	  dfs(adj, used, ordering, adj[x][i]);
  }
  ordering.insert(ordering.begin(), x);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> ordering;
  for (int i = 0; i < adj.size(); i++) {
	if (!used[i]) {
	  dfs(adj, used, ordering, i);
	}
  }
  return ordering;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> ordering = toposort(adj);
  for (size_t i = 0; i < ordering.size(); i++) {
    std::cout << ordering[i] + 1 << " ";
  }
}
