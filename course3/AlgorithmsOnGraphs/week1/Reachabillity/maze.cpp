#include <iostream>
#include <vector>

using namespace std;
using std::vector;

void find(int v, vector<vector<int> >& adjacent, vector<bool> &visit) {

	visit[v] = true;

	for (int i = 0; i < adjacent[v].size(); i++) {

		int z = adjacent[v][i];

		if (!visit[z])
			find(z, adjacent, visit);

	}

}


int reach(vector<vector<int> > &adjacent, int x, int y) {

	vector<bool> visit;
	visit.resize(adjacent.size());

	find(x, adjacent, visit);

	if (visit[x] && visit[y])
		return 1;

	return 0;

}


int main() {

	int m, n;
	cin >> n >> m;

	vector<vector<int> > adjacent(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int x, y;
		cin >> x >> y;

		adjacent[x - 1].push_back(y - 1);
		adjacent[y - 1].push_back(x - 1);

	}

	int x, y;
	cin >> x >> y;

	cout << reach(adjacent, x - 1, y - 1);

}
