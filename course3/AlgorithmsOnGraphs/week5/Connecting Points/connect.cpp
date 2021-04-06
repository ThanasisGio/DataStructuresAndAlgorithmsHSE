#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

struct node {
  int par_node;
  int ranking;
  int x;
  int y;
	
  node(int a, int b, int c = -1, int d = 0) {
    x = a;
    y = b;
    par_node = c;
    ranking = d;
  }
};

struct edges {
  int u;
  int v;
  double weight;
  
  edges(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};

bool cmp(edges a, edges b) {
  return a.weight < b.weight;
}

void make(int i, vector<node> &nodes, vector<int> &x, vector<int> &y) {
  nodes.push_back(node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Find(int i, vector<node> &nodes) {
  if (i != nodes[i].par_node) {
    nodes[i].par_node = Find(nodes[i].par_node, nodes);
  }
  return nodes[i].par_node;
}

void merge(int u, int v, vector<node> &nodes) {
  int r1 = Find(u, nodes);
  int r2 = Find(v, nodes);
  if (r1 != r2) {
    if (nodes[r1].ranking > nodes[r2].ranking) {
      nodes[r2].par_node = r1;
    } else {
      nodes[r1].par_node = r2;
      if (nodes[r1].ranking == nodes[r2].ranking) {
        nodes[r2].ranking++;
      }
    }
  }
}

double min_dis(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  int n = x.size();
  vector<node> nodes;
  for (int i = 0; i < n; i++) {
	make(i, nodes, x, y);
  }
  vector<edges> edgess;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edgess.push_back(edges(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }
  std::sort(edgess.begin(), edgess.end(), cmp);
  for (int i = 0; i < edgess.size(); i++) {
    edges current_edges = edgess[i];
    int u = current_edges.u;
    int v = current_edges.v;
    if (Find(u, nodes) != Find(v, nodes)) {
      result += current_edges.weight;
      merge(u, v, nodes);
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << min_dis(x, y) << std::endl;
}
