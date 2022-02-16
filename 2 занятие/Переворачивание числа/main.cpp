#include <iostream>

void swap(int &x){
    int temp = x;
    x = 0;
    while(temp != 0){
        x = x*10 + temp%10;
        temp = temp/10;
    }
}

int main() {
    int x;
    std::cin>>x;
    swap(x);
    std::cout<<x<<"\n";
    return 0;
}