#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
int main()
{
    using namespace std::complex_literals;
    std::cout<<std::fixed<<std::setprecision(1);
    std::cout<<"This is only to test the c++11 complex header features\n";
    std::complex<double> z1 = 1i * 1i;
    std::complex<double> z2 = pow(z1,2);
    double PI = std::acos(-1);
    // std::complex<double> z3 = std::exp(1i*PI);
    std::complex<double> z4,z5;
    z4 = 1. + 2i;
    z5 = 1. - 2i; 
    std::cout<<"i*i:"<<z1<<" i*i*i*i:"<<z2
    // <<" e^(PI*i):"<<z3
    <<" (1+2i)*(1-2i):"<<(z4*z5)<<"\n";
    return 0;
}