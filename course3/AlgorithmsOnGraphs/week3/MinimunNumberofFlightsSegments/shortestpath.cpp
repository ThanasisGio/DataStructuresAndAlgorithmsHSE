#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {

	vector<int> distan;
	distan.resize(adj.size());

	for (int i = 0; i < adj.size(); i ++)
		distan[i] = -1;

	distan[s] = 0;
        //make queue
	queue<int> A;
        // enqueu the current node
	A.push(s);

	while (!A.empty()) {

		int s = A.front();
		A.pop();

		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

			if (distan[*i] == -1) {

				A.push(*i);
				distan[*i] = distan[s] + 1;

			}
		}
	}

	return distan[t];

}

int main() {

	int n, m;
	cin >> n >>m;

	vector<vector<int> > adj(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int x, y;

		cin >> x >> y;

		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);

	}

	int s, t;
	cin >> s >> t;

	cout << distance(adj, s - 1, t - 1);

	return 0;

}
