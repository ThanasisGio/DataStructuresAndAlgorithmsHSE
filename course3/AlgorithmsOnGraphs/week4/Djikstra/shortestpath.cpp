#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <set>
#include <queue>

using namespace std;

struct Node {

	int vertice;
	int distance;

	Node(int vertice, int distance) : vertice(vertice), distance(distance) {}

	bool operator>(const Node & rhs) const {return this->distance > rhs.distance;}
};

int cost_of_flight(vector<vector<int>> &adj, vector<vector<int>> cost, int s, int e) {

	vector<int> distance(adj.size(), INT_MAX);

	distance[s] = 0;

	priority_queue < Node, vector<Node>, greater<Node> > pq;

	pq.push(Node(s, 0));

	set<int> proceded;

	while (!pq.empty()) {

		auto curr = pq.top();
		pq.pop();

		int current_ind = curr.vertice;

		for (int i = 0; i < adj[current_ind].size(); i++) {

			int n = adj[current_ind][i];

			if (distance[n] > distance[current_ind] + cost[current_ind][i]) {

				distance[n] = distance[current_ind] + cost[current_ind][i];

				pq.push(Node(n, distance[n]));

			}
		}

		proceded.insert(current_ind);

	}

	if (distance[e] == INT_MAX){
		return -1;
	}

	else
		return distance[e];

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());

	for (int i = 0; i < m; i++) {

		int u, v, w;
		cin >> u >> v >> w;

		adj[u - 1].push_back(v - 1);
		cost[u - 1].push_back(w);

	}

	int x, y;
	cin >> x >> y;

	cout << cost_of_flight(adj, cost, x - 1, y - 1);

	return 0;

}
