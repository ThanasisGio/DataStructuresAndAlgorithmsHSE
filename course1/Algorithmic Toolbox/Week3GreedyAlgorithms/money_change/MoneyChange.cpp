#include <iostream>

int get_change(int n) {
    int coins[] = {10, 5, 1}, Numcoin=0;
    

    for (int i = 0; n > 0; i++) {
        Numcoin = Numcoin + n / coins[i];
        n = n%coins[i];
    }
    return Numcoin;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_change(n) << '\n';
}
