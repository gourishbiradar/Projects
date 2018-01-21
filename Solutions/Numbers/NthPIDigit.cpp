#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class BBP
{
    int n; //the digits to be calculated
    double pi; //calculated pi value
    char pi_hex[14]; //Hex representation of pi value
    //Functions
    double s(int); //The Function to find sums based on input
    long ModExpo(int,int,int); //Modular expo function base,exponent,modulus are inputs
    void Hex(double, char[]);
    public:
    BBP(int input=1) //default of 1 digit precision
    {
        this->n = input;
    }
    double CalculatePI();
};
void BBP::Hex(double pi, char ch[])
{
    double y;
    int i;
    const char hex[] = "0123456789ABCDEF";
    y = fabs(pi);
    for(i=0;i<16;i++)
    {
        y = 16.0 * (y-floor(y));
        ch[i] = hex[(int)y];
    }
}
long BBP::ModExpo(int base, int expo, int modulus)
{
    long result;
    if(expo==0) return 1;
    result = ModExpo(base,expo>>1,modulus);
    result = (result*result)%modulus;
    if((expo%2)==1) result = (result*base)%modulus;
    return result;
}
double BBP::s(int j)
{
    double s = 0.0;
    double t;
    int denominator;
    int k;
    double precision = 1.0e-17;
    //left sum (integer part)
    for(k=0;k<=n;k++)
    {
        denominator = 8*k + j;
        t = (double)ModExpo(16,(n-k),denominator);
        t/=denominator;
        s+= t - (int)t;
        s-=(int)s;
    }
    //Right sum (fractional part)
    while(1)
    {
        denominator = 8*k+j;
        t = pow(16.0,(double)(n-k));
        t/=(double)denominator;
        if(t<precision) break;
        s+=t;
        s-=(int)s;
        k++;
    }
    return s;
}
double BBP::CalculatePI()
{
    pi = 4.0*s(1) - 2.0*s(4) - s(5) - s(6);
    pi = pi - (int)pi + 1.0;
    Hex(pi,pi_hex);
    printf("Fraction: %.15f\n",pi);
    printf("Hex digits: %10.10s\n",pi_hex);
    return pi;
}

int main()
{
    int n;
    cout<<"Enter the nth position of pi to evaluate:";
    cin>>n;
    BBP obj(n);
    double value = obj.CalculatePI();
    system("pause");
    return 0;
}