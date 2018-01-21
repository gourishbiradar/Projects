#include <iostream>
#include <cmath>
#define PREC 18
using namespace std;
unsigned int fact(int n)
{
    unsigned int i;
    unsigned int val=1;
    for(i=1;i<=n;i++)
        val = val*i;
    return val;
}
int main(int argc, char** argv)
{
    if(argc<1)
    {
        cout<<"Please enter the digit upto which 'e' needs to be calculated!!";
        system("pause");
        return -1;
    }
    int n = atoi(argv[1]);
    int N = n;
    if(n<1)
    {
        cout<<"Please enter a digit greater than 1";
        system("pause");
        return -1;
    }
    if(n>PREC)
    {
        cout<<"Can't caculate a digit beyound "<<PREC<<endl;
        system("pause");
        return -1;
    }
    if(n<5)
    n = 5;

    double e=1.0;
    for(int i=1;i<=n;i++)
        e+=(1.0/fact(i));
    printf("e=%.*f\n",N,e);
    system("pause");
    return 0;
}