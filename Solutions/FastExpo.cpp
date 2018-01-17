#include <iostream>
#include <ctime>
using namespace std;
double BinaryExponentiation(double x, int n)
{
    if(n<0)
        return BinaryExponentiation(1/x, -n);
    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(n&1) //is n odd?
        return x*BinaryExponentiation(x*x,(n-1)>>1);
//if n is even
return BinaryExponentiation(x*x,n>>1);
}
//TODO make it work for real number powers?
//TODO manage larn number outputs since they are not returned in double
int main()
{
    double num,power;
    cout<<"Enter a number:";
    cin>>num;
    cout<<"Enter the power:";
    cin>>power;
    clock_t t0,t1;
    t0 = clock();
    double solution = BinaryExponentiation(num,power);
    t1 = clock();
    double tt = (double)(t1-t0)/CLOCKS_PER_SEC;
    cout<<"The number "<<num<<" raised to "<<power<<" is "<<solution<<" in time:"<<tt;
    return 0;
}