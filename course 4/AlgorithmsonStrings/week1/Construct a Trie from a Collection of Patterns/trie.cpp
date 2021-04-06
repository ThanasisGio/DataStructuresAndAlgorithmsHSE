#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

using edges = map<char, int>;
using trie = vector<edges>;

trie build_trie(vector<string>& patterns) {

	if (patterns.empty())
		return trie{};

	trie t{edges{}};

	int root_node = 0;
	int count = 0;

	for(auto & pattern : patterns){

		int curr = root_node;

		for (auto s: pattern) {

			if (t[curr].find(s) != t[curr].end())
				curr = t[curr][s];

			else {

				t.emplace_back(edges{});
				t[curr][s] = ++count;
				curr = count;

			}
		}

	}

	return t;

}

int main() {

	size_t n;
	cin >> n;
	

	vector<string> patterns(n);

	for (size_t i = 0; i < n; i++) {

		string s;
		cin >> s;
		

		patterns.push_back(s);

	}

	trie t = build_trie(patterns);

	for (size_t i = 0; i < t.size(); i++) {

		for (const auto & j : t[i])
			cout << i << "->" << j.second << ":" << j.first << endl;
	}

	return 0;


}
