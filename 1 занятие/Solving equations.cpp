
#include <iostream>

#include <cmath>

int main () {
    float a,b,c;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    std::cout<<a<<"x^2"<<" + "<<b<<"x"<<" + "<<c<<" = 0"<<"\n";
    float d = b*b - 4*a*c;
    if (a != 0) {
        if (d < 0){
        std::cout<<"-1"<<"\n";
    } 
    if (d > 0) {
        std::cout<<"x_1"<<" = "<<(-b - std::sqrt(d))/(2*a)<<"\n";
        std::cout<<"x_2"<<" = "<<(-b + std::sqrt(d))/(2*a)<<"\n";
    }
    if (d == 0) {
        std::cout<<"x"<<" = "<<(-b - std::sqrt(d))/(2*a)<<"\n";
    }
        
    } if(a == 0) {
        if (b != 0) {
            std::cout<<"x"<<" = "<<(-c)/(b)<<"\n";
        } else {
            if (c != 0){
                std::cout<<"solutions dont exist"<<"\n";
            } else {
                std::cout<<"R";
            }
        }
    }
    
    
    
    
    return 0;
}
