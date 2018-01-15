#include <iostream>
#include <limits> 
using namespace std;
bool primes[INT_FAST16_MAX];
void sieve(int n)
{
    int i;
    if(n<2)
    return ; // no primes smaller than 2
    for(i=2;i<INT_FAST16_MAX;i++)
        primes[i]=true;
    for(i=4;i<INT_FAST16_MAX;i+=2)
    primes[i]=false;
    for(i=3;i*i<INT_FAST16_MAX;i+=2)
    {
        if(primes[i])
        {
            for(int j=i;j<INT_FAST16_MAX;j+=i)
                primes[j]=false;
            primes[i]=true;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter a number upto which primes are to be calculated:";
    cin>>n;
    if(n>INT_FAST16_MAX)
        n=INT_FAST16_MAX;
    sieve(n);
    cout<<"Primes lower than "<<n<<" are :";
    for(int i=2;i<=n;i++)
    {
        if(primes[i])
            cout<<i<<" ";
    }
    system("pause");
    return 0;
}