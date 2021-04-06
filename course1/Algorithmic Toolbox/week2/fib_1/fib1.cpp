#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
     int x=0,y=1,store;
   if(n==0)
     return x;
    else if (n==1)
     return y ;
   for (int i = 2 ; i<=n; i++){
    if ( n > 0)
    {
     store = x + y;
     x=y;
     y= store;
     }

}

    return store;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n){
        assert(fibonacci_fast(n) == fibonacci_naive(n));
       }
}

int main() {
     int n ;
      std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
