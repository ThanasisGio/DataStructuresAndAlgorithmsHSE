#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool partitionlook(const vector<long long>& A, int z,
					  vector<long long>& parts, long long tar) {
	if (z >= A.size()) return true;
	for (size_t i = 0; i < parts.size(); i++) {
		if (parts[i] + A.at(z) <= tar) {
			parts[i] = parts[i] + A.at(z);
			if (partitionlook(A, z + 1, parts, tar)) {
				return true;
			}
			parts[i] = parts[i] - A.at(z);
		}
	}
	return false;
}

bool partition3(vector<long long>& A) {
	long long a = accumulate(A.begin(), A.end(), 0);
	
	if (a % 3 != 0 or A.size() < 3 or
		*max_element(A.begin(), A.end()) > a / 3) {
		
		return false;
	}

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	vector<long long> partitions(3, 0);
	return partitionlook(A, 0, partitions, a / 3);
}

int main() {
	int n;
	std::cin >> n;
	vector<long long> A(n);
	for (size_t i = 0; i < A.size(); ++i) { std::cin >> A[i]; }
	std::cout << partition3(A) << '\n';
}
