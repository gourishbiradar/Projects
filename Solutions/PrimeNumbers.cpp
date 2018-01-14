#include <iostream>
#include <vector>
using namespace std;

#define MAXN 10001
bool primes[MAXN];
void sieve()
{
    int i;
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
    int flag;
    int i;
    cout<<"Enter 1 to stop";
    cout<<"Primes:\n";
    sieve();
    vector<int> Result;
    for(i=2;i<MAXN;i++)
    {
        if(primes[i])
            Result.push_back(i);
    }
    i=0;
    do
    {
        cin>>flag;
        cout<<Result[i++]<<" ";
        if(i==MAXN)
        break;
    }while(flag!=1);
    system("pause");
    return 0;
}