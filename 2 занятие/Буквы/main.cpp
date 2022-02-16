#include <iostream>

void foo(int n){
    int temp = 0;
    int m = 0;
    while(m != n) {
        while (temp < n - m) {
            char x = 65 + temp;
            std::cout << x;
            temp++;
        }
        for (int i = 1; i < 2*m; i++) {
            std::cout << ' ';
        }
        while (temp > 0){
            if(temp == n){
                --temp;
            }
            char x = 64 + temp;
            std::cout << x;
            temp--;
        }
        std::cout << '\n';
        ++m;
    }
}

int main() {
    int n;
    std::cout << "Please, write the number n" << std::endl;
    std::cin>>n;
    foo(n);
    return 0;
}
