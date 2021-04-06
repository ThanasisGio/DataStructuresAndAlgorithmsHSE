#include <iostream>
#include <vector>

using std::vector;

int max (vector<int> weights, vector<int> values) {
    int max1 = 0;
    double max2 = 0;

    for (int i = 0; i < weights.size(); i++) {
         
        if (weights[i] != 0 && (double)values[i]/weights[i] > max2) {
            max2 = (double)values[i]/weights[i];
            max1 = i;
        }
    }
    return max1;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) 
          return value;
        int j = max(weights, values);
        int a = std::min(capacity, weights[j]);
        value = value + a *(double)values[j]/weights[j];
        capacity = capacity - a;
        weights[j] = weights[j] - a;
        
    }

    return value;
}


int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
