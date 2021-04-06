#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int DFS(vector<vector<int> > &adjacent, int x, vector<int> &visit, vector<int> &recursionstack) {
  
  visit[x] = 1;
  recursionstack[x] = 1;
 
  for (int i = 0; i < adjacent[x].size(); i++) {
    if (!visit[adjacent[x][i]] && DFS(adjacent, adjacent[x][i], visit, recursionstack))
	  return 1;
	else if(recursionstack[adjacent[x][i]])
	  return 1;
  }
  recursionstack[x] = 0;
    return 0; 
}

int acyclic(vector<vector<int> > &adjacent) {
 
  vector<int> visit(adjacent.size());
  vector<int> recursionstack(adjacent.size());
  for (int i = 0; i < adjacent.size(); i++)
  {
    if (!visit[i]) {
      if (DFS(adjacent, i, visit, recursionstack)) 
        return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adjacent(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adjacent[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adjacent);
}
