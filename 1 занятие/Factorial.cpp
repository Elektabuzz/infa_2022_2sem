/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{
    int x;
    std::cin>>x;
    int f = 1;
    for (int i=1; i <= x; ++i) {
        f = f*i;
    }
    std::cout<<"Factorial = "<<f;
}
