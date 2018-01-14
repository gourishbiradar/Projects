#include <iostream>
#include <limits> 
using namespace std;

#define MAXN INT_MAX
bool primes[MAXN];
void sieve(int n)
{
    int i;
    if(n<2)
    return ; // no primes smaller than 2
    for(i=2;i<MAXN;i++)
        primes[i]=true;
    for(i=4;i<MAXN;i+=2)
    primes[i]=false;
    for(i=3;i*i<MAXN;i+=2)
    {
        if(primes[i])
        {
            for(int j=i;j<MAXN;j+=i)
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
    if(n>MAXN)
        n=MAXN;
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