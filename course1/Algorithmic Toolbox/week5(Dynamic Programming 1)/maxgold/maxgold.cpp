#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
	vector<vector<int>> matrix(w.size() + 1 , vector<int>(W + 1 ));
	for (size_t i = 0; i <= W; i++){ 
              matrix[0][i] = 0; }
	for (size_t i = 0; i <= w.size(); i++) { matrix[i][0] = 0; }

	for (size_t i = 1; i <= w.size(); i++) {
		for (size_t j = 1; j <= W; j++) {
			if (j >= w[i - 1]) {
				matrix[i][j] = max(w[i - 1] + matrix[i - 1][j - w[i - 1]],
								   matrix[i - 1][j]);
			} else {
				matrix[i][j] = matrix[i - 1][j];
			}
		}
	}

	return matrix[w.size()][W];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) { std::cin >> w[i]; }
	std::cout << optimal_weight(W, w) << '\n';
}
