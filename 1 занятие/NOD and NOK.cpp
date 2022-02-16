/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

int main()
{
    int a, b;
    std::cin>>a>>b;
    int r1, r2, r3;
    r1 = a;
    r2 = b;
    r3 = b;
    while (r1%r2 != 0) {
        r3 = r1%r2;
        r1 = r2;
        r2 = r3;
    }
    std::cout<<"NOD = "<<r3<<"\n";
    std::cout<<"NOK = "<<(a*b)/(r3);

    return 0;
}
