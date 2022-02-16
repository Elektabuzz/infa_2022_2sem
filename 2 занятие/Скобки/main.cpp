#include <iostream>

bool check(int n){
    int m = 0;
    char x;
    while(n != 0 and m >= 0){
        std::cout<<"please write bra '(' or cket ')'"<<"\n";
        std::cin>>x;
        if(x == '('){
            m += 1;
        } else{
            m -= 1;
        }
        n -= 1;
    }
    return m == 0;
}

int main() {
    int n;
    std::cout<<"please, write the number"<<"\n";
    std::cin>>n;
    if(check(n)){
        std::cout<<"The sequence is right"<<"\n";
    } else {
        std::cout<<"The sequence is not right"<<"\n";
    }
    return 0;
}
