#include <iostream>
#include <cmath>

bool simple(int x){
    bool t = true;
    for (int j = 2; j < std::sqrt(x); ++j) {
        if (x % j == 0) {
            t = false;
        }
    }
    return t;
}

int swap(int x){
    int temp = 0;
    while(x > 0){
        temp = temp*10 + x%10;
        x = x/10;
    }
    return temp;
}

bool palendrom(int x) {
    return x == swap(x);
}

int main() {
    std::cout<<"please write the number 'n' "<<"\n";
    int n;
    std::cin>>n;
    for(int i = 0; i < n; ++i){
        int x;
        std::cout<<"please write the int number"<<"\n";
        std::cin>>x;
        if(simple(x)){
            std::cout<<"x - simple"<<"\n";
        } else {
            std::cout<<"x - not simple"<<"\n";
        }
        if(palendrom(x)){
            std::cout<<"x - palendrom"<<"\n";
        } else {
            std::cout<<"x - not palendrom"<<"\n";
        }

    }
    return 0;
}